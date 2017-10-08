//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include "singleton.h"

TEST(test_creation, get_id) {
	singleton* first_instance = singleton::get_instance();
	EXPECT_EQ(first_instance->get_instances_count(), 1);

	singleton* second_instance = singleton::get_instance();
	EXPECT_EQ(second_instance->get_instances_count(), 2);
	first_instance->kill();

	EXPECT_EQ(second_instance->get_instances_count(), 1); 

}
