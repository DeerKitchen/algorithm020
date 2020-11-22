/**
*  合并两个有序链表
*
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(nullptr == l1) return l2;
        if(nullptr == l2) return l1;
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        ListNode* temp;
        while(nullptr != l1 || nullptr != l2) {
            if(nullptr != l1 && nullptr != l2) {
                if(l1->val >= l2->val) {
                    temp = l2;
                    l2 = l2->next;
                }else {
                    temp = l1;
                    l1 = l1->next;
                }
            }else if(nullptr != l1 && nullptr == l2) {
                temp = l1;
                l1 = l1->next;
            }else if(nullptr == l1 && nullptr != l2) {
                temp = l2;
                l2 = l2->next;
            }
            head->next = temp;
            head = head->next;
        }
        return res->next;
    }
};
