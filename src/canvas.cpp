#include "canvas.h"
#include "common.h"
//y + HEIGHT* (x + WIDTH* z)
using namespace life;

void Canvas::pixel(const Point2& pt, const Color& color)
{

    for (auto y(pt.y * m_block_size); y < pt.y* m_block_size + m_block_size; y++)
    {
        for (auto x(pt.x * m_block_size ); x < pt.x * m_block_size + m_block_size; x++)
        {
            m_pixels[ y * m_width * image_depth +  x*image_depth + 0] = color.channels[0]; 
            m_pixels[ y * m_width * image_depth +  x*image_depth + 1] = color.channels[1];
            m_pixels[ y * m_width * image_depth +  x*image_depth + 2] = color.channels[2];
            m_pixels[ y * m_width * image_depth +  x*image_depth + 3] = 255;
        }

    }
}