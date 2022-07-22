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

namespace linked_movements
{
    namespace movement_profiles
    {
        struct ramp_params
        {
            double a_max;
            double v_min;
            double v_max;
        };

        class trapezoidal_ramp
        {
        public:
        void update_params(ramp_params params);
        private:
            ramp_params params;
            double t_max;
            double diff_max;
        };
    }
    void link_profiles();

}
