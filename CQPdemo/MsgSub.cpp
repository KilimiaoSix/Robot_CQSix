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
//字匂繁譜協葎溺突憩性
std::string RobotName_EN = "FiLa";
std::string RobotName_ZN = "憩性";

//擬秘畠蕉延楚 ac   壓appmain.h 嶄協吶
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
		
			/*				宥	喘				*/
			

			if (msg.msg=="!enter debug" &&msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "序秘debug庁塀");
				flag_debug = true;  //序秘debug庁塀
			}
			else if (msg.msg == "弌幽燉" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "麼繁低挫��");
			}
			else if (msg.msg == "弌幽燉低挫" && msg.fromQQ == 1048597043) 
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "麼繁挫��書爺匆仭逗阻");
			}
			else if ((msg.msg == "弌幽燉"))
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "燉?");
			}
			else if (msg.msg == "弌幽燉牘牘" && msg.fromQQ != 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "萩��萩音勣宸劔燉�。�");
			}
			else if (msg.msg == "寵寵弌幽燉" && msg.fromQQ != 1048597043)
			{
				i = random(4);
				if(i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "萩´´萩艶委厘輝弌頃徨燉��");
				else if(i == 2)
					CQ_sendGroupMsg(ac, msg.fromGroup, "艶岱寵晴燉�　�´");
				else if(i == 3)
				{
					CQ_sendGroupMsg(ac, msg.fromGroup, "寵遊氏海音互議燉��");
				}
				else
				{
					CQ_sendGroupMsg(ac, msg.fromGroup, "艶岱寵燉��具伉燉��");
				}
			}
			else if (msg.msg == "弌幽燉牘牘" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "麼繁匆牘牘��~~~~燉");
			}
			else if (msg.msg == "寵寵弌幽燉" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "麼繁議寵寵挫穂捲燉~~~");
			}
			else if(msg.msg == "弌幽燉��逸厘独墾今鮹徨"&& msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "今鮹徨頁株DD��DD kimo");
			}
			else if ((msg.msg.find("浪散") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg.find("cocomi suki") == -1 &&(msg.msg.find("浪散") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg == "諮 欠徨 諮" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "諮 欠徨 諮");
			}
			else if (msg.msg == "弌幽燉��逸厘独墾爺徨" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "tanko伊蛍咄憲疹挫阻燉�訊�繁吉彭勣椿燉");
			}	
			else if (msg.msg.find("cocomi suki") != -1 && msg.msg.find("suki") != -1 && msg.fromQQ == 1048597043 && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "麼繁低嗽DD阻");
			}
			else if (msg.msg == "弌幽燉��逸厘独墾仔析医" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "仔析医酔溺廾");
			}
			else if (msg.msg == "仟繁卯孚" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "仟繁卯孚");
			}//独墾仟繁
			else if (msg.msg == "pjt酔卯孚" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "pjt酔卯孚��");
			}//独墾屠助摸
			else if (msg.msg == "仟繁序蛤乎孤焚担" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "及匯��枠心蛤巷御��及屈��個蛤兆頭��及眉��卯孚窟碕淫��");
			}//仟繁戻幣

		/*
				##############喘噐独墾##############			
		
																					*/

			////Dalou科軌
			//if (msg.msg == "!hello" && msg.fromQQ == 1061566571) {
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "�贄Σ睚塋О棕�獏獏獏");
			//	 

			//}

			//if (msg.fromGroup == 982711563) {
			//	if (msg.msg == "諮 仔析医 諮") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "諮 仔析医 諮");
			//		 
			//	}
			//	else if (msg.msg == "磨 仔析医 磨") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "磨 仔析医 磨");
			//		 
			//	}
			//	else if (msg.msg == "独墾仔析医") {
			//		int PICKS;
			//		PICKS = random(4);

			//		switch (PICKS){
			//		 case 1: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "溺廾  仔析医  溺廾");
			//			break;
			//		 }case 2: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "コウちゃん 溺廾�。�");
			//			break;
			//		 }case 3: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "Kou輯~~~~溺廾�。�");
			//			break;

			//		 }
			//		 default:
			//		 {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "仔析医酔溺廾��"); 
			//		 }
			//		}      
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "楹") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "楹�〇得楼� 楹��");
			//		 
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "��") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "? Kou輯 ?");
			//		 
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "�殖殖�") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "??? Kou輯 ???");
			//		 
			//	}
			//}

			///*else */ if (msg.msg == "!sleep") {
			//	//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "おやすみなさい、お麼繁��゛");
			//	 
			//}

			//else if (msg.msg == "!易兆汽賦萩") {
			//	//CQ_sendGroupMsg(ac, msg.fromGroup, "萩暴祖InkBot�〃∨幼禝�ID");
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "徭強賦萩狼由撒渠阻(�丕潯�)�仝�厘肇野燕��音亟阻��醍軍棒阻��https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
			//	 
			//}
			//else if (msg.msg == "!github") { 
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "https://github.com/inkchan2333/inkchan"); 
			//	 
			//}
			//else if (msg.msg == "!酒汽屁栽淫") 
			//{
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "燉(>^ω^<)�腎�栽淫和墮仇峽�� https://cola.sayobot.cn/inkcake/Minecraft%201.12.2%20IC2%20forge2768%20Shaders.zip");
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "仍仍匚第第議堝徒屶隔��");
			//	 
			//}



			/* 
			
								####  戻佰  ###
			
																		*/
			else if (msg.msg == "仍捨琉" || msg.msg == "捨琉")
			{
				CQ_sendPrivateMsg(ac, 1048597043, "嗤繁出低��");
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
	//泌惚産贋議��連寄噐100柳  夸岷俊砺虹仟欺議��連
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}


