#include "stdafx.h"
#include "MsgSub.h"
#include "cqp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define random(x) (rand()%x)
#include <string.h>
bool flag_debug = false;
int i = 0;
//机器人设定为女仆菲拉
std::string RobotName_EN = "FiLa";
std::string RobotName_ZN = "菲拉";

//导入全局变量 ac   在appmain.h 中定义
extern int ac;
bool Find(char* a,char* str)  
{
		if (strstr(str, a) != NULL)
		{	
			return true;
		}
		else
		{
			return false;
		}
}
/*bool OsuGroups(msg.fromGroup) {

}
*/
void GroupMsgSub::threadMain()
{
	while (!m_quit)
	{
		if (m_groupMsgBuffer.size() > 0)
		{
			m_mutex.lock();
			GroupMsg msg = m_groupMsgBuffer.front();
			m_groupMsgBuffer.pop();
			m_mutex.unlock();
		
			/*				通	用				*/
			

			if (msg.msg == "!github")  //代码开源
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "GitHub代码:https://github.com/KilimiaoSix/Robot_CQSix.git 目前版本是：1.0.3");
			}
			else if (msg.msg == "小桐喵" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人你好！");
			}
			else if (msg.msg == "小桐喵你好" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人好，今天也辛苦了");
			}
			else if ((msg.msg == "小桐喵"))
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "喵?");
			}
			else if (msg.msg == "小桐喵啾啾" && msg.fromQQ != 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "请，请不要这样喵！！");
			}
			else if (msg.msg == "摸摸小桐喵" && msg.fromQQ != 1048597043)
			{
				i = random(4);
				if (i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "请……请别把我当小孩子喵！");
				else if (i == 2)
					CQ_sendGroupMsg(ac, msg.fromGroup, "别乱摸啦喵！……");
				else if (i == 3)
				{
					CQ_sendGroupMsg(ac, msg.fromGroup, "摸头会长不高的喵！");
				}
				else
				{
					CQ_sendGroupMsg(ac, msg.fromGroup, "别乱摸喵，恶心喵！");
				}
			}
			else if (msg.msg == "小桐喵啾啾" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人也啾啾！~~~~喵");
			}
			else if (msg.msg == "摸摸小桐喵" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人的摸摸好舒服喵~~~");
			}
			else if (msg.msg == "小桐喵，帮我迫害海蛎子" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "海蛎子是臭DD！DD kimo");
			}
			else if ((msg.msg.find("喜欢") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg.find("cocomi suki") == -1 && (msg.msg.find("喜欢") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg == "火 风子 火" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "火 风子 火");
			}
			else if (msg.msg.find("cocomi suki") != -1 && msg.msg.find("suki") != -1 && msg.fromQQ == 1048597043 && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人你又DD了");
			}
			else if (msg.msg == "小桐喵，帮我迫害黄老板" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "黄老板快女装");
			}
			else if (msg.msg == "小桐喵，我想玩服务器怎么办" && msg.fromGroup == 765455518)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "第一步，请安装Java，第二步，请购买正版官方国际服并下载启动器，第三步，安装mod，第四步，新服可以直接进，旧服请填写群文件的表注册白名单谢谢！如果还不明白请看群公告");
			}
			else if (msg.msg == "!MC" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac,msg.fromGroup,"要玩MC的加群765455518");
			}
			else if (msg.msg == "!白名单注册" && msg.fromGroup == 765455518)  //软件注册还没搞定，稍等
				CQ_sendGroupMsg(ac, msg.fromGroup, "我还没搞定软件注册，要注册的自己填表 https://docs.qq.com/sheet/DZEJQb3dCb0piRXF0?preview_token=&coord=H7%24H7%240%240%240%240&tab=BB08J2");
			else if (msg.msg == "!服务器地址" && msg.fromGroup == 765455518)
				CQ_sendGroupMsg(ac, msg.fromGroup, "旧服务器：[inkcake.sayobot.cn:25565] 新服务器： [inkcake.sayobot.cn:23333]");
			//----------------------分割线-----------------------------------//
			//---------------------------------------------------------------//
			else if (msg.msg == "新人爆照" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "新人爆照");
			}//迫害新人
			else if (msg.msg == "pjt快爆照" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "pjt快爆照！");
			}//迫害潘锦涛
			else if (msg.msg == "新人进群该干什么" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "第一，先看群公告，第二，改群名片，第三，爆照发红包！");
			}//新人提示
		
		}
		else
		{
			ThreadBase::mSleep(10);
		}
	}
	return;
}

GroupMsgSub::GroupMsgSub()
{
	m_quit = false;
}

GroupMsgSub::~GroupMsgSub()
{
}

void GroupMsgSub::start()
{
	m_quit = false;
	ThreadBase::start();
}

void GroupMsgSub::quite()
{
	ThreadBase::quit();
	m_quit = true;
}


void GroupMsgSub::pushMsg(int32_t msgId, int64_t fromGroup, int64_t fromQQ, std::string msg)
{
	//如果缓存的消息大于100跳  则直接抛弃新到的消息
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}


