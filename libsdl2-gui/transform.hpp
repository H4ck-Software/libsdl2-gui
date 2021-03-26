#pragma once

#include <cmath>

/**
 * \brief Transform2d Struct.
 */
struct Transform2d
{
    struct position
    {
            /**
             * \brief X coordinate.
            */
            float x;
            /**
             * \brief Y coordinate.
            */
            float y;
    } position;

    struct scale
    {
            /**
             * \brief X scale.
            */
            float x;
            /**
             * \brief Y scale.
            */
            float y;
    } scale;
};
