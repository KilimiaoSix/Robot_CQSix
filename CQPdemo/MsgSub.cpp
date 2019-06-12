#include "stdafx.h"
#include "MsgSub.h"
#include "cqp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#define random(x) (rand()%x)
#include <string.h>
bool flag_debug = false;
int i = 0;
//机器人设定为女仆菲拉
std::string RobotName_EN = "FiLa";
std::string RobotName_ZN = "菲拉";

//导入全局变量 ac   在appmain.h 中定义
extern int ac;
/*bool OsuGroups(msg.fromGroup) {

}
*/
void TimeJudge(SYSTEMTIME &st,GroupMsg &msg,bool master_t)
{
	if (st.wHour >= 5 && st.wHour < 11)  //早上时间
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "主人，早上好！今天也请继续努力加油吧喵~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "早上好喵！新的一天继续加油喵~！");
		}
	}
	else if (st.wHour >= 11 && st.wHour < 15)  //中午时间
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "主人，中午好！午饭有好好吃喵？~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "午安desu~喵！");
		}
	}
	else if (st.wHour >= 15 && st.wHour < 18)  //下午时间
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "主人，下午好！~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "下午好喵~！");
		}
	}
	else if (st.wHour >= 18 && st.wHour < 23)  //晚上时间
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "主人，晚上好！~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "喵！？晚上好desu喵~");
		}
	}
	else  //深夜
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "主人，很迟了哦~~，快去睡，群里有我看守");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "zzzzzzzzzzz我困了喵~~");
		}
	}
}
//用于每天打招呼！
void Say_Hello(SYSTEMTIME& st, GroupMsg& msg, bool master_t)
{
	if (msg.msg == "小桐喵，早上好")
	{
		if (st.wHour >= 5 && st.wHour < 11)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人早上好！新的一天也一起加油吧！");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "早上好desu喵！新的一天也要好好工作哦！");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，现在可不是早上哦~！");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "现在可不是早上哦！");
		}
	}
	else if (msg.msg == "小桐喵，中午好")
	{
		if (st.wHour >= 11 && st.wHour < 15)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，中午好！要好好吃午饭然后好好地睡一觉哦！");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "午安~~~！");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，现在可不是中午哦~睡迷糊了吗？");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "？？？");
		}
	}
	else if (msg.msg == "小桐喵，下午好")
	{
		if (st.wHour >= 15 && st.wHour < 18)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，下午好！要好好去学习（工作）哦！");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "下午好！要好好去学习（工作）哦！");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，现在可不是下午哦~mofumofu~");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "早就不是下午了哦~");
		}

	}
	else if (msg.msg == "小桐喵，晚上好")
	{
		if (st.wHour >= 15 && st.wHour < 18)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，晚上好！");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "晚上好哦~！");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，现在可不是晚上哦~啾啾~");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "emmmm好像不是晚上哦~");
		}
	}
	else if (msg.msg == "小桐喵，晚安")
	{
		if (st.wHour >= 23 || (st.wHour >= 0 && st.wHour < 5))
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，晚安！今天一天也辛苦了，好好休息哦！");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "晚安！");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人，现在可不是睡觉的时间哦");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "别睡了，太阳晒屁股了！");
		}
	}
	
}
void Time_Message(SYSTEMTIME& st, GroupMsg& msg)
{
	char str[200];
	sprintf(str, "现在的时间是：%d 时 %d 分", st.wHour, st.wMinute);
	CQ_sendGroupMsg(ac,msg.fromGroup,str);
}
void GroupMsgSub::threadMain()
{
	while (!m_quit)
	{
		if (m_groupMsgBuffer.size() > 0)
		{
			m_mutex.lock();
			SYSTEMTIME st = { 0 };
			GetLocalTime(&st);
			GroupMsg msg = m_groupMsgBuffer.front();
			m_groupMsgBuffer.pop();
			m_mutex.unlock();
		
			/*				通	用				*/
			

			if (msg.msg == "!github")  //代码开源
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "GitHub代码:https://github.com/KilimiaoSix/Robot_CQSix.git 目前版本是：1.0.4");
			}
			else if (msg.msg == "!词库编辑")
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "请填表：https://docs.qq.com/sheet/DZHB4SVRvaGtEeWVq?preview_token=&coord=C14%24C14%240%240%240%240&tab=BB08J2");
				CQ_sendGroupMsg(ac, msg.fromGroup, "不要教些乱七八糟的东西哦！");
			}
			else if (msg.msg == "小桐喵" && msg.fromQQ == 1048597043)
			{
				TimeJudge(st,msg,true);
			}
			else if (msg.msg == "小桐喵你好" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人好，今天也辛苦了");
			}
			else if ((msg.msg == "小桐喵"))
			{
				TimeJudge(st, msg, false);
			}
			else if (msg.msg == "小桐喵啾啾" && msg.fromQQ != 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "请，请不要这样喵！！");
			}
			else if (msg.msg == "摸摸小桐喵" && msg.fromQQ != 1048597043)
			{
				i = random(4);
				if (i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "mofumofu~！");
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
			else if (msg.msg == "小桐喵真可爱" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "wwwwwwwwwwwww");
			}
			else if (msg.msg == "小桐喵啾啾" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人也啾啾！~~~~喵");
			}
			else if (msg.msg == "摸摸小桐喵" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人的mofumofu~~~");
			}
			else if (msg.msg == "小桐喵，帮我迫害海蛎子" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "海蛎子什么时候女装出道喵？");
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
			else if (msg.msg.find("cocomi suki") == -1 && msg.msg.find("suki") != -1 && msg.fromQQ == 1048597043 && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人你又DD了");
			}
			else if (msg.msg == "小桐喵，帮我迫害黄老板" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "黄老板快女装");
			}
			else if (msg.msg == "小桐喵，我想玩MC怎么办" && msg.fromGroup == 765455518)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "第一步，请安装Java，第二步，请购买正版官方国际服并下载启动器，第三步，安装mod，第四步，新服可以直接进，旧服请填写群文件的表注册白名单谢谢！如果还不明白请看群公告");
			}
			else if (msg.msg == "!MC" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "要玩MC的加群765455518");
			}
			else if (msg.msg == "迫害海蛎子" && msg.fromGroup == 982711563)
			{
				int i = random(2);
				if(i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "[CQ:image,file=1.jpg]");
				else
					CQ_sendGroupMsg(ac, msg.fromGroup, "[CQ:image,file=2.jpg]");
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
			else if (msg.msg == "小桐喵，现在几点了" || msg.msg == "!time" || msg.msg == "!时间")
			{
				Time_Message(st,msg);
			}
			//////打招呼！
			else if (msg.msg == "小桐喵，早上好" || msg.msg == "小桐喵，中午好" || msg.msg == "小桐喵，下午好" || msg.msg == "小桐喵，晚上好" || msg.msg == "小桐喵，晚安")
			{
				if (msg.fromQQ == 1048597043)
				{
					Say_Hello(st, msg, true);
				}
				else
				{
					Say_Hello(st, msg, false);
				}
			 }
			else if (msg.msg == "小桐喵劝劝黄老板" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "kou酱，那个，女装出道好不好。");
			}
			else if (msg.msg == "糕姐姐嘶哈嘶哈" && (msg.fromGroup == 982711563 ||  msg.fromGroup == 765455518))
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "糕姐姐嘶哈嘶哈");
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


