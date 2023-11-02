/*-------------------------------------------------------------------*\
|  RGBController_QMKOpenRGBRevE.h                                     |
|                                                                     |
|  Driver for QMK keyboards using OpenRGB Protocol (Revision E)       |
|                                                                     |
|  Kasper       10th Octobber 2020                                    |
|  Jath03       28th May 2021                                         |
|  HorrorTroll  11th July 2022                                        |
\*-------------------------------------------------------------------*/

#pragma once

#include "RGBController.h"
#include "QMKOpenRGBRevDController.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

#define NO_LED 0xFFFFFFFF

typedef std::vector<std::vector<unsigned int>> VectorMatrix;

class RGBController_QMKOpenRGBRevE : public RGBController
{
public:
    RGBController_QMKOpenRGBRevE(QMKOpenRGBRevDController* controller_ptr, bool save);
    ~RGBController_QMKOpenRGBRevE();

    void                                    SetupZones();
    void                                    ResizeZone(int zone, int new_size);

    void                                    DeviceUpdateLEDs();
    void                                    UpdateZoneLEDs(int zone);
    void                                    UpdateSingleLED(int led);

    void                                    DeviceUpdateMode();
    void                                    DeviceSaveMode();

private:
    QMKOpenRGBRevDController*   controller;
    std::vector<unsigned int>   flat_matrix_map;
    std::vector<unsigned int>   flat_underglow_map;

    void                                    InitializeMode
                                            (
                                            std::string name,
                                            unsigned int &current_mode,
                                            unsigned int flags,
                                            unsigned int color_mode,
                                            bool save
                                            );

    unsigned int                            CalculateDivisor
                                            (
                                            std::vector<point_t> led_points,
                                            std::set<int> rows,
                                            std::set<int> columns
                                            );

    void                                    CountKeyTypes
                                            (
                                                std::vector<unsigned int>   led_flags,
                                                unsigned int                total_led_count,
                                                unsigned int&               key_leds,
                                                unsigned int&               underglow_leds
                                            );

    void                                    PlaceLEDsInMaps
                                            (
                                                std::set<int>               unique_rows,
                                                std::set<int>               unique_cols,
                                                unsigned int                divisor,
                                                std::vector<point_t>        led_points,
                                                std::vector<unsigned int>   led_flags,
                                                VectorMatrix&               matrix_map_xl,
                                                VectorMatrix&               underglow_map_xl
                                            );

    VectorMatrix                            MakeEmptyMatrixMap
                                            (
                                            unsigned int height,
                                            unsigned int width
                                            );

    void                                    CleanMatrixMaps
                                            (
                                            VectorMatrix&   matrix_map,
                                            VectorMatrix&   underglow_map,
                                            unsigned int    height,
                                            bool            has_underglow
                                            );

    std::vector<unsigned int>               FlattenMatrixMap
                                            (
                                            VectorMatrix matrix_map
                                            );
};
