THREADINGAPP_VERSION = 1.0
THREADINGAPP_SOURCE = $(THREADINGAPP_VERSION).tar.gz
THREADINGAPP_LICENSE = MIT

define THREADINGAPP_BUILD_CMDS
    $(TARGET_MAKE_ENV) $(CC) -o $(@D)/threadingapp src/main.c -lpthread
endef

$(eval $(generic-package))
