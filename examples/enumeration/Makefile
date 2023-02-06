#--- Global variables -------------------------------------------------------------------
include ../../Makefile.common
CXX          = g++
CXXFLAGS     = -O3 -Wall -g
OBJ_DIR      = ../../obj
SRC_DIR      = .
INC_DIR      = ../../core/include
LIB_DIR      = ../../lib
INCS         = -I$(INC_DIR)
LIBS         = -L$(LIB_DIR) -l$(GLOBAL_TARGET) -lcln
FILES_EXT    = cpp
SRC          = $(notdir $(wildcard $(SRC_DIR)/*.$(FILES_EXT)))
OBJ          = $(SRC:%.$(FILES_EXT)=$(OBJ_DIR)/%.o)
LOCAL_TARGET = enumeration

#--- Rules ------------------------------------------------------------------------------
all: header depend $(LOCAL_TARGET) footer

header:
	@echo "[ $(LOCAL_TARGET) ]"

depend:
	@echo -n "  + Generate dependencies : "
ifneq ($(strip $(SRC)),)
	@$(CXX) $(INCS) -MM $(SRC:%=$(SRC_DIR)/%) \
	| sed -e 's:^[^ ]:$(OBJ_DIR)/&:' > Makefile.depend
endif
	@echo "OK"

$(LOCAL_TARGET): $(OBJ)
	@echo -n "  + Build $@ : "
	@$(CXX) $(CXXFLAGS) $(INCS) $^ $(LIBS) -o $@
	@echo "OK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILES_EXT)
	@echo -n "  + Compile $(notdir $@) : "
	@$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@
	@echo "OK"

clean: header
	@echo -n "  + Delete objects and bin : "
	@\rm -rf $(LOCAL_TARGET) $(OBJ)
	@echo "OK"

footer:

.PHONY: clean

include Makefile.depend
