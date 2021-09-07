# 御坂网络驱动-RGB Bling

## 介绍

御坂网络驱动-RGB Bling 软件包提供了 RGB LED 的控制接口

### 目录结构

| 名称                    | 说明         |
| ----------------------- | ------------ |
| Examples                | 例程         |
| Misaka_rgb_bling.h      | 使用头文件   |
| Misaka_rgb_bling.c      | 使用源代码   |
| Misaka_rgb_bling_port.c | 移植文件     |
| README.md               | 驱动使用说明 |

### 许可证

御坂网络驱动-RGB Bling 软件包遵循 Apache-2.0 许可，详见 LICENSE 文件。

### 依赖

无依赖。

## API

### 初始化

```C
void Misaka_rgb_bling_init(uint16_t time_base)
```

_初始化函数_

| _参数_      | _描述_     |
| :---------- | ---------- |
| _time_base_ | _调用周期_ |

### 设置工作模式

```C
void Misaka_rgb_bling_mode_set(Misaka_RGB_Bling_Color_Enum color1,
                           Misaka_RGB_Bling_Color_Enum color2,
                           uint32_t color1_time,
                           uint32_t color2_time,
                           uint16_t cnt,
                           uint8_t endless_flag);
```

_工作模式设置_

| _参数_         | _描述_        |
| -------------- | ------------- |
| _color1_       | _颜色 1_      |
| _color2_       | _颜色 2_      |
| _color1_time_  | _颜色 1 时间_ |
| _color2_time_  | _颜色 2 时间_ |
| _cnt_          | _次数_        |
| _endless_flag_ | _无尽模式_    |

### 周期处理函数

```c
void Misaka_rgb_bling_cycle_process();
```

_周期处理函数_

> 需要周期性调用，如果为裸机程序，也可在中断中调用。

### 引脚设置

```c
void Misaka_set_bling_pin(Misaka_RGB_Bling_Color_Enum color);
```

_设置RGB颜色的物理层函数_

| _参数_  | _描述_ |
| ------- | ------ |
| _color_ | _颜色_ |

## 如何增加颜色

```C
typedef enum
{
    Misaka_RGB_Bling_Color_None = 0,
    Misaka_RGB_Bling_Color_Red,
    Misaka_RGB_Bling_Color_Green,
    Misaka_RGB_Bling_Color_Blue,
    Misaka_RGB_Bling_Color_Yellow,
    Misaka_RGB_Bling_Color_Cyan,
    Misaka_RGB_Bling_Color_White,
    Misaka_RGB_Bling_Color_Purple,
} Misaka_RGB_Bling_Color_Enum;
```

​	在此处添加上所需要的颜色，然后在`Misaka_set_bling_pin`上添加对应颜色的物理层即可。
