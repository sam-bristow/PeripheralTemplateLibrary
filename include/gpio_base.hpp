/*
 * This file is part of the Peripheral Template Library project.
 *
 * Copyright (c) 2012 Paul Sokolovsky <pfalcon@users.sourceforge.net>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _GPIO_BASE_HPP
#define _GPIO_BASE_HPP

#include <stdio.h>
#include <stdint.h>
#include <bits.hpp>
#include <types.hpp>
#include <inline.hpp>

class IPort
{
public:
    // Enable port for access (power on, set up clocks, etc.)
    static void enable() {}
    // Disable port (power off)
    static void disable() {}
};

template <class pin_impl>
class IPin
{
public:
    static void output();
    static void input();
    // TODO: need better type
    static int  value();
    static void high();
    static void low();
    static void toggle();
    static void set(bool8 val)
    {
        if (val)
            pin_impl::high();
        else
            pin_impl::low();
    }
    static void pulloff();
    static void pullup();
    static void pulldown();
};

class NullPin : public IPin<NullPin>
{
public:
    typedef class NullPort {} port;
    ALWAYS_INLINE static void output() {}
    ALWAYS_INLINE static void high() {}
    ALWAYS_INLINE static void low()  {}
};

#endif //_GPIO_BASE_HPP
