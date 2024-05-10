/* 
 * File:   color.cpp
 * Author: Renann Prado
 * 
 * Created on July 7, 2014, 12:43 AM
 */

#include "color.h"

namespace tin
{
    color::color(int red, int green, int blue, int alpha)
	: red(red), green(green), blue(blue), alpha(alpha)
    {
	
    }
    
    color::color()
    {
	this->red = 0;
	this->green = 0;
	this->blue = 0;
	this->alpha = 255;
    }
    
    void color::set_red(int _new_value)
    {
	this->red = _new_value;
    }
    
    void color::set_green(int _new_value)
    {
	this->green = _new_value;
    }
    
    void color::set_blue(int _new_value)
    {
	this->blue = _new_value;
    }
    
    void color::set_alpha(int _new_value)
    {
	this->alpha = _new_value;
    }
    
    int color::get_red()
    {
	return this->red;
    }
    
    int color::get_green()
    {
	return this->green;
    }
    
    int color::get_blue()
    {
	return this->blue;
    }
    
    int color::get_alpha()
    {
	return this->alpha;
    }
    
    color::~color()
    {
	
    }
}
