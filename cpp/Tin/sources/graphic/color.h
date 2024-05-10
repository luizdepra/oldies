/* 
 * File:   color.h
 * Author: Renann Prado
 *
 * Created on July 7, 2014, 12:43 AM
 */

#ifndef COLOR_H
#define	COLOR_H

namespace tin
{
    class color 
    {
        public:
            color(int, int, int, int);
            /**
             * Creates a color object with following default values:
             * red, green and blue = 0
             * alpha = 255
             */
            color();
            void set_red(int);
            void set_green(int);
            void set_blue(int);
            void set_alpha(int);
            int get_red();
            int get_green();
            int get_blue();
            int get_alpha();
            virtual ~color();
        private:
            int red;
            int green;
            int blue;
            int alpha;
    };
}
#endif	/* COLOR_H */