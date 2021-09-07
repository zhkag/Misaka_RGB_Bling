/**
 * @file Misaka_rgb_bling_port.c
 * @brief
 * @author xqyjlj (xqyjlj@126.com)
 * @version 0.0
 * @date 2021-08-02
 * @copyright Copyright © 2020-2021 xqyjlj<xqyjlj@126.com>
 *
 * *********************************************************************************
 * @par ChangeLog:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-08-02 <td>0.0     <td>xqyjlj  <td>内容
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
    switch (color)
    {
    case Misaka_Bling_Color_None:
    {

    }
    break;
    case Misaka_Bling_Color_Red:
    {

    }
    break;
    case Misaka_Bling_Color_Green:
    {

    }
    break;
    case Misaka_Bling_Color_Blue:
    {

    }
    break;
    case Misaka_Bling_Color_Yellow:
    {

    }
    break;
    case Misaka_Bling_Color_Cyan:
    {

    }
    break;
    case Misaka_Bling_Color_White:
    {

    }
    break;
    case Misaka_Bling_Color_Purple:
    {

    }
    break;
    default:
    {

    }
    break;
    }
}