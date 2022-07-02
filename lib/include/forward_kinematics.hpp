#include "blaze/Math.h"
#include "tracking.hpp"
namespace forward_kinematics
{
    enum class SimpleProgress
    {
        not_reached,
        reached,
        already_reached,
    };

    enum class RequestState
    {
        received_new_star,
        no_stars_available,
        pulled_with_error
    };
    /**
     * @brief Tracks movement progress of a single star from received frames.
     * Automatically requests a new star after marking previous as reached.
     *
     */
    class SingleStarEstimator
    {
    public:
        SingleStarEstimator();
        SimpleProgress SetNewStar(tstar set_star);
        bool ApplyCheckCube(double d);                //< Attaches a 3d-Box around the star. Reduces Precision for Speed.
        SimpleProgress IsStarReached(tstar cmp_star); //<Checks if endpoint of Arm is located at requested star.
        RequestState RequestNewStar();                //< Pull new star from ringbuffer.
        SimpleProgress CalculateMovementDirection();
        SimpleProgress CalculateMovementContinuity();
        tstar ApplyCalmanFilter(double x_p,double x_v,double a_x);
        bool SetOffsets(std::int32_t b_x, std::int32_t b_y, std::int32_t b_z);
        void SetKalmanGain(double k_x, double k_y, double k_z);
        void SetMatrix(blaze::StaticMatrix<double,3UL,3UL> a);

    private:
        double distance;
        tstar target_star;
        blaze::StaticVector<int, 3UL> last_statematrix;
        blaze::StaticVector<int, 3UL> bias;
        blaze::StaticMatrix<double, 3UL, 3UL> A;
        double kalman_gain;
    };

    class MultiStarEstimator
    {
    public:
        MultiStarEstimator();
    };

};