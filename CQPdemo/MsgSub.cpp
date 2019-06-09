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
			

			if (msg.msg=="!enter debug" &&msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "进入debug模式");
				flag_debug = true;  //进入debug模式
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
				if(i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "请……请别把我当小孩子喵！");
				else if(i == 2)
					CQ_sendGroupMsg(ac, msg.fromGroup, "别乱摸啦喵！……");
				else if(i == 3)
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
			else if(msg.msg == "小桐喵，帮我迫害海蛎子"&& msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "海蛎子是臭DD！DD kimo");
			}
			else if ((msg.msg.find("喜欢") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg.find("cocomi suki") == -1 &&(msg.msg.find("喜欢") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg == "火 风子 火" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "火 风子 火");
			}
			else if (msg.msg == "小桐喵，帮我迫害天子" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "tanko八分音符烤好了喵？主人等着要呢喵");
			}	
			else if (msg.msg.find("cocomi suki") != -1 && msg.msg.find("suki") != -1 && msg.fromQQ == 1048597043 && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人你又DD了");
			}
			else if (msg.msg == "小桐喵，帮我迫害黄老板" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "黄老板快女装");
			}
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

		/*
				##############用于迫害##############			
		
																					*/

			////Dalou彩蛋
			//if (msg.msg == "!hello" && msg.fromQQ == 1061566571) {
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "响应测试失败，嘤嘤嘤");
			//	 

			//}

			//if (msg.fromGroup == 982711563) {
			//	if (msg.msg == "火 黄老板 火") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "火 黄老板 火");
			//		 
			//	}
			//	else if (msg.msg == "酸 黄老板 酸") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "酸 黄老板 酸");
			//		 
			//	}
			//	else if (msg.msg == "迫害黄老板") {
			//		int PICKS;
			//		PICKS = random(4);

			//		switch (PICKS){
			//		 case 1: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "女装  黄老板  女装");
			//			break;
			//		 }case 2: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "コウちゃん 女装！！");
			//			break;
			//		 }case 3: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "Kou酱~~~~女装！！");
			//			break;

			//		 }
			//		 default:
			//		 {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "黄老板快女装！"); 
			//		 }
			//		}      
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "艹") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "艹！黄老板 艹！");
			//		 
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "？") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "? Kou酱 ?");
			//		 
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "？？？") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "??? Kou酱 ???");
			//		 
			//	}
			//}

			///*else */ if (msg.msg == "!sleep") {
			//	//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "おやすみなさい、お主人様～");
			//	 
			//}

			//else if (msg.msg == "!白名单申请") {
			//	//CQ_sendGroupMsg(ac, msg.fromGroup, "请私聊InkBot！发送你的ID");
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "自动申请系统坏掉了(┬＿┬)！给我去填表，不写了，麻烦死了，https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
			//	 
			//}
			//else if (msg.msg == "!github") { 
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "https://github.com/inkchan2333/inkchan"); 
			//	 
			//}
			//else if (msg.msg == "!简单整合包") 
			//{
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "喵(>^ω^<)？整合包下载地址： https://cola.sayobot.cn/inkcake/Minecraft%201.12.2%20IC2%20forge2768%20Shaders.zip");
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "谢谢夜妈妈的云盘支持！");
			//	 
			//}



			/* 
			
								####  提醒  ###
			
																		*/
			else if (msg.msg == "谢嘉伟" || msg.msg == "嘉伟")
			{
				CQ_sendPrivateMsg(ac, 1048597043, "有人叫你！");
			}
		
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


