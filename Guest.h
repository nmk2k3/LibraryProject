#pragma once
#include "User.h"
#include "Member.h"
class Guest : public User
{
public:
	Guest();
	Member* signup();
};

