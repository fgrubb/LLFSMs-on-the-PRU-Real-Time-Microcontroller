
#include "Resource_Table_Wrapper.h"

#ifdef PRU1
#include "resource_table_RPMSG_data_1.h"
#else
#include "resource_table_RPMSG_data_0.h"
#endif

Resource_Table_Wrapper::Resource_Table_Wrapper () {

	to_resourceTable = &resourceTable;
}
