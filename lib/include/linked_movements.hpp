/**
 * @file linked_movements.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <etl/vector.h>

namespace linked_movements
{
    namespace movement_profiles
    {
        struct ramp_params
        {
            double a_max;
            double da_max;
            double v_min;
            double v_max;
        };

        enum class ramp_error
        {
            no_error = 0,
            acceleration_to_low = 1,
            too_short_deacceleration = 2,
        };

        class generic_ramp
        {
        protected:
            generic_ramp(){};

        public:
            virtual ~generic_ramp(){};

            virtual double v(int t, double diff_position) = 0;
            virtual void update_params(ramp_params params) = 0;
            virtual ramp_error recalculate_ramp(int ramp_time, double new_position) = 0;

        private:
            virtual double get_start_position() = 0;
            virtual double get_start_speed() = 0;
            ramp_params params;
            double t_max;
            double diff_max;
        };

        class trapezoidal_ramp : public generic_ramp
        {
        public:
            trapezoidal_ramp(){};
            ~trapezoidal_ramp(){};
            void update_params(ramp_params new_params);
            ramp_error recalculate_ramp(int ramp_time, double new_position);
            double v(int t, double diff_position);

        private:
            double get_start_position();
            double get_start_speed();
            ramp_params params;
            double t_max;
            double diff_max;
        };
    }

    class ramp_factory{

    };

    class sync_manager
    {
    public:
        void synchronize_childs(int sync_time);
        void link_child(movement_profiles::generic_ramp *new_child);

    private:
        etl::vector<movement_profiles::generic_ramp *, 10> childs;
    };

}
