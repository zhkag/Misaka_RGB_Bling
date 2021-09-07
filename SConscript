from building import * 

# get current dir path
cwd = GetCurrentDir()

# init src and inc vars
src = []
inc = [cwd]

# add Misaka_rgb_bling source code
src = src + ['Misaka_rgb_bling.c']

if GetDepend('PKG_USING_MISAKA_RGB_BLING_DEMO'):
    src = src + ['Examples/Misaka_rgb_bling_port_rtt.c']
else:
	src = src + ['Misaka_rgb_bling_port.c']
	
# add group to IDE project
group = DefineGroup('Misaka_rgb_bling', src, depend = ['PKG_USING_MISAKA_RGB_BLING'], CPPPATH = inc)

Return('group')
