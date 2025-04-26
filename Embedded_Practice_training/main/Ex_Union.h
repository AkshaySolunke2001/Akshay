#ifndef EX_UNION_H
#define EX_UNION_H
#ifdef __cplusplus
extern "C" {
#endif
void get_planet_distance_from_sun();
enum Planet {
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE,
    PLANET_COUNT
};

union Distance_from_Sun_to_planet {
    enum Planet planet_enum;
    float distance_from_Sun;
};



#ifdef __cplusplus
}
#endif

#endif
