/**
 * @file Misaka_rgb_bling_port_rtt.c
 * @brief
 * @author xqyjlj (xqyjlj@126.com)
 * @version 0.0
 * @date 2021-09-07
 * @copyright Copyright © 2020-2021 xqyjlj<xqyjlj@126.com>
 *
 * *********************************************************************************
 * @par ChangeLog:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-09-07 <td>0.0     <td>xqyjlj  <td>内容
 * </table>
 * *********************************************************************************
 */

/**
 * @brief 设置Misaka_RGB_Bling的GPIO引脚
 * @param  color            颜色
 */
#include "Misaka_rgb_bling.h"
#include <rtthread.h>
#include <rtdevice.h>

#ifndef RGB_R
    #define RGB_R            GET_PIN(B,  0)  /* PB0 */
#endif
#ifndef RGB_G
    #define RGB_G            GET_PIN(B,  1)  /* PB1 */
#endif
#ifndef RGB_B
    #define RGB_B            GET_PIN(B,  2)  /* PB2 */
#endif

/**
 * @brief                   设置RBG颜色引脚
 * @param  color            颜色
 */
void Misaka_set_bling_pin(Misaka_RGB_Bling_Color_Enum color)
{
    switch (color)
    {
    case Misaka_RGB_Bling_Color_None:
    {
        rt_pin_write(RGB_R, PIN_LOW);
        rt_pin_write(RGB_G, PIN_LOW);
        rt_pin_write(RGB_B, PIN_LOW);
    }
    break;
    case Misaka_RGB_Bling_Color_Red:
    {
        rt_pin_write(RGB_R, PIN_HIGH);
        rt_pin_write(RGB_G, PIN_LOW);
        rt_pin_write(RGB_B, PIN_LOW);
    }
    break;
    case Misaka_RGB_Bling_Color_Green:
    {
        rt_pin_write(RGB_R, PIN_LOW);
        rt_pin_write(RGB_G, PIN_HIGH);
        rt_pin_write(RGB_B, PIN_LOW);
    }
    break;
    case Misaka_RGB_Bling_Color_Blue:
    {
        rt_pin_write(RGB_R, PIN_LOW);
        rt_pin_write(RGB_G, PIN_LOW);
        rt_pin_write(RGB_B, PIN_HIGH);
    }
    break;
    case Misaka_RGB_Bling_Color_Yellow:
    {
        rt_pin_write(RGB_R, PIN_HIGH);
        rt_pin_write(RGB_G, PIN_HIGH);
        rt_pin_write(RGB_B, PIN_LOW);
    }
    break;
    case Misaka_RGB_Bling_Color_Cyan:
    {
        rt_pin_write(RGB_R, PIN_LOW);
        rt_pin_write(RGB_G, PIN_HIGH);
        rt_pin_write(RGB_B, PIN_HIGH);
    }
    break;
    case Misaka_RGB_Bling_Color_White:
    {
        rt_pin_write(RGB_R, PIN_HIGH);
        rt_pin_write(RGB_G, PIN_HIGH);
        rt_pin_write(RGB_B, PIN_HIGH);
    }
    break;
    case Misaka_RGB_Bling_Color_Purple:
    {
        rt_pin_write(RGB_R, PIN_HIGH);
        rt_pin_write(RGB_G, PIN_LOW);
        rt_pin_write(RGB_B, PIN_HIGH);
    }
    break;
    default:
    {
        rt_pin_write(RGB_R, PIN_LOW);
        rt_pin_write(RGB_G, PIN_LOW);
        rt_pin_write(RGB_B, PIN_LOW);
    }
    break;
    }
}

static char bling_thread_stack[256];
static struct rt_thread bling_thread;

void bling_thread_entry(void* parameter)
{
    while (1)
    {
        rt_thread_mdelay(100);
        Misaka_rgb_bling_cycle_process();
    }
}

/**
 * @brief            Misaka_RGB_Bling线程初始化函数
 * @return int @c
 */
static int bling_thread_setup(void)
{
    Misaka_rgb_bling_init(100);
    /**
     * @brief 即为开机按照100ms的周期闪烁10次
     */
    Misaka_rgb_bling_mode_set(Misaka_RGB_Bling_Color_Cyan,
                              Misaka_RGB_Bling_Color_Blue,
                              100,
                              100,
                              10,
                              0);
    rt_thread_init(&bling_thread,
                   "bling_thread",
                   bling_thread_entry,
                   RT_NULL,
                   &bling_thread_stack[0],
                   sizeof(bling_thread_stack),
                   22, 100);
    rt_thread_startup(&bling_thread);
    return 0;
}

INIT_APP_EXPORT(bling_thread_setup);





