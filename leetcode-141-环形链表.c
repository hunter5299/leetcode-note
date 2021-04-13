#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

 

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/linked-list-cycle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


struct ListNode {
	int val;
	struct ListNode *next;
	
};
#define bool int;
#define false 0;
#define true 1;
/*使用快慢指针来判断是否为环，若能两指针能走到一起，则是环*/
bool hasCycle(struct ListNode *head) {
	struct ListNode* slow, *fast;
	slow = head;
	fast = head;

	while ((fast != NULL) && (fast->next != NULL)) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast){
			return true;
		}
	}

	return false;
}
/*
	延展：
	1.为什么slow走一步，fast走两步，他们就一定能在环内相遇呢？会不会永远追不上？
		答：假设slow进环时，fast与slow的距离是N，追击的过程中，fast走两步
			slow走一步，每次移动，它们之间的距离缩小1，
			N,
			N-1
			N-2
			···
			2
			1
			0；
			距离缩小到0的时候相遇
			
			
	2.slow走一步，fast走3，4步？走n步行不行？为什么？
		答：根据环的大小，两指针追击完一圈，有可能fast会错过slow
			如：N是偶数，fast每次走3步，则没走一次距离缩小2
			则N-2，N-4···，2，0，就一定会相遇，
				N是奇数，fast没走3步，则有可能错过，若此时环的长度C-1也是奇数，
			那么fast就永远也追不上slow了

		总结：若slow进环时，slow跟fast的差距N是奇数，且环的长度是偶数，fast每次走3步，则追不上


	3.求环的入口点？
		设：链表头到环入口点的距离是L
			环的大小是C
			入口到相遇点的距离是X
			slow到入口时，fast已经走了N圈
			当slow进环后，一圈内就会被fast追上
			则到相遇时，slow走了L+X的距离
						fast走了L+N*C+X
						 
						fast走了2倍slow的路程
			此时得到一个等式:  2(L+X) = L+ N*C +X
						=>      L = N*C -X;
			即，一个指针meet从相遇点开始往后走，一个指针head从表头开始走
			meet与head相遇的时候就是入口点
		leetcode 142 求入口点 
*/