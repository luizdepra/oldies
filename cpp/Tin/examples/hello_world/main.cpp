/*
 * File:   main.cpp
 * Author: RawArkanis
 *
 * Created on June 28, 2014, 10:57 AM
 */

#include <iostream>
#include <memory>

#include <application.h>

using namespace std;
using namespace tin;

int main(int argc, char** argv)
{
    auto my_app = make_shared<application>();

    cout << "Done!" << endl;

    return 0;
}
