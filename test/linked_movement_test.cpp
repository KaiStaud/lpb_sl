#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "../lib/include/linked_movements.hpp"

using namespace linked_movements;
using namespace movement_profiles;


TEST_CASE("Error checking for trapezoidal ramp")
{
    trapezoidal_ramp tp1;
    ramp_params params{
        .a_max =2,
        .da_max= 2,
        .v_max = 4,
    };
    tp1.update_params(params);
    CHECK(tp1.recalculate_ramp(10,10) == ramp_error::no_error);
    CHECK(tp1.recalculate_ramp(1,10) == ramp_error::acceleration_to_low);
    CHECK(tp1.recalculate_ramp(5,10) == ramp_error::too_short_deacceleration);

}

TEST_CASE("Synchronizing three kinematic objects")
{
    trapezoidal_ramp tp1,tp2,tp3;
    sync_manager s;
    ramp_params params{
        .a_max =2,
        .da_max= 2,
        .v_max = 4,
    };
    s.link_child(&tp1);
    s.link_child(&tp2);
    s.link_child(&tp3);

    tp1.update_params(params);
    tp2.update_params(params);
    tp3.update_params(params);

    s.synchronize_childs(10);
}