//Leetcode 2. Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 2/3/2018 - A solid 27.50th percentile boys

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry_over = 0;
        int sum = 0;
        int one = 0;
        int two = 0;

        sum = l1->val + l2->val;
        if (sum >= 10)
        {
            sum = sum % 10;
            carry_over = 1;
        }

        ListNode* sum_list = new ListNode(sum);
        ListNode* curr_node = sum_list;

        while (l1->next != NULL || l2->next != NULL)
        {
            if (l1->next != NULL)
            {
                l1 = l1->next;
                one = l1->val;
            }
            else
            {
                one = 0;
            }

            if (l2->next != NULL)
            {
                l2 = l2->next;
                two = l2->val;
            }
            else
            {
                two = 0;
            }

            sum = one + two + carry_over;

            carry_over = 0;
            if (sum >= 10)
            {
                sum = sum % 10;
                carry_over = 1;
            }


            curr_node->next = new ListNode(sum);
            curr_node = curr_node->next;

        }
        // Deal with the final carry over
        if (carry_over == 1)
        {
            curr_node->next = new ListNode(1);
        }

        return sum_list;
    }
};