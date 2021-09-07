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
 * @brief 设置Misaka_Bling的GPIO引脚
 * @param  color            颜色
 */
#include "Misaka_rgb_bling.h"

/**
 * @brief                   设置RBG颜色引脚
 * @param  color            颜色
 */
void Misaka_Set_Bling_GPIO(Misaka_Bling_Color_Enum color)
{
    /**
     * @brief 此处为STM32 LL库的示例
     */
    switch (color)
    {
    case Misaka_Bling_Color_None:
    {
        LL_GPIO_ResetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_ResetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_ResetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    case Misaka_Bling_Color_Red:
    {
        LL_GPIO_SetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_ResetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_ResetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    case Misaka_Bling_Color_Green:
    {
        LL_GPIO_ResetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_SetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_ResetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    case Misaka_Bling_Color_Blue:
    {
        LL_GPIO_ResetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_ResetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_SetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    case Misaka_Bling_Color_Yellow:
    {
        LL_GPIO_SetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_SetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_ResetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    case Misaka_Bling_Color_Cyan:
    {
        LL_GPIO_ResetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_SetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_SetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    case Misaka_Bling_Color_White:
    {
        LL_GPIO_SetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_SetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_SetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    case Misaka_Bling_Color_Purple:
    {
        LL_GPIO_SetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_ResetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_SetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    default:
    {
        LL_GPIO_ResetOutputPin(RGB_R_GPIO_Port, RGB_R_Pin);
        LL_GPIO_ResetOutputPin(RGB_G_GPIO_Port, RGB_G_Pin);
        LL_GPIO_ResetOutputPin(RGB_B_GPIO_Port, RGB_B_Pin);
    }
    break;
    }
}