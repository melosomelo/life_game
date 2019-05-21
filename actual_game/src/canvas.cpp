#include "../include/canvas.h"
#include "../include/common.h"
//y + HEIGHT* (x + WIDTH* z)
#include "../include/canvas.h"



namespace life
{
    void Canvas::clear (void)
    {
        for(int i = 0; i < this->m_pixels.size(); i++)
        {
            if(i % 3 == 0)
                continue;
            m_pixels[i] = 255;
        }
    }
    void life::Canvas::pixel( const life::Point2& point,  const life::Color& color )
    {   
        for( int y = point.y*m_block_size; y < (point.y + 1)*m_block_size; y++)
            for( int x = point.x*m_block_size; x < (point.x + 1)*m_block_size; x++ )
            { 
                m_pixels[ y * m_width * image_depth +  x*image_depth + 0] = color.channels[0]; 
                m_pixels[ y * m_width * image_depth +  x*image_depth + 1] = color.channels[1];
                m_pixels[ y * m_width * image_depth +  x*image_depth + 2] = color.channels[2];
                m_pixels[ y * m_width * image_depth +  x*image_depth + 3] = 255;
            }
    }
    Color Canvas::pixel(const Point2 & point) const
    {
        int offset = point.y * 4 * this->m_width + point.x * 4;
        Color result(this->m_pixels[offset], this->m_pixels[offset+1], this->m_pixels[offset+2]);
        return result;
    }

}
