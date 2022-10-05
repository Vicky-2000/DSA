class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(-1);
        List<Integer> list = new ArrayList<>();
        ListNode current = head;

        for(ListNode first : lists){
            while(first != null){
                list.add(first.val);
                first = first.next;
            }
        }

        Collections.sort(list);
        int i = 0;
        while(i != list.size()){
            current.next = new ListNode(list.get(i));
            current = current.next;
            i++;
        }

        return head.next;
    }
}
