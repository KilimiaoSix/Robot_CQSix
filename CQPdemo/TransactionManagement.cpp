
#include "stdafx.h"
#include "TransactionManagement.h"


TransactionManagement* TransactionManagement::getInstance()
{
	static TransactionManagement* t= new TransactionManagement();
	return t;
}

GroupMsgSub * TransactionManagement::getGroupMsgSubInstance()
{
	return m_groupMsgSub;
}

TransactionManagement::TransactionManagement()
{
	m_groupMsgSub = new GroupMsgSub();
}


TransactionManagement::~TransactionManagement()
{
}
