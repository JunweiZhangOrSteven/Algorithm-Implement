import javafx.util.Pair;

import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode() {}
     TreeNode(int val) { this.val = val; }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
         this.left = left;
         this.right = right;
     }
}
//class Node {
//    public int val;
//    public Node left;
//    public Node right;
//    public Node next;
//
//    public Node() {}
//
//    public Node(int _val) {
//        val = _val;
//    }
//
//    public Node(int _val, Node _left, Node _right, Node _next) {
//        val = _val;
//        left = _left;
//        right = _right;
//        next = _next;
//    }
//};
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
class ProductOfNumbers {

    List<Integer> list = null;
    List<Integer> preSum = null;
    public ProductOfNumbers() {
        list = new ArrayList<>();
        preSum = new ArrayList<>();
    }

    public void add(int num) {
        list.add(num);
        if(preSum.isEmpty()){
            preSum.add(1);
        }
        if(num == 0){
            preSum.clear();
            return;
        }
        preSum.add(preSum.get(preSum.size() - 1) * num);
    }

    public int getProduct(int k) {
        if(preSum.size() - k < 0)return 0;
        int index = preSum.size() - k - 1;
        int end = preSum.size() - 1;
        return preSum.get(end) / preSum.get(index);
    }
}
public class Solution {

    Map<TreeNode,Integer> map = new HashMap<>();
    public int[] findMode(TreeNode root) {
        inorder(root);
        List<Integer> res = new ArrayList<>();
        int mostFrequent = Collections.max(map.values());
        for(Map.Entry<TreeNode,Integer> entry : map.entrySet()){
            if(entry.getValue() == mostFrequent && !res.contains(entry.getKey().val))res.add(entry.getKey().val);
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
    public void inorder(TreeNode node){
        if(node == null)return;
        map.put(node,map.getOrDefault(node,0) + 1);
        inorder(node.left);
        inorder(node.right);
    }
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int left = 0,right = m * n - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            int x = mid/n;
            int y = mid%n;
            if(matrix[x][y] == target){
                return true;
            }else if(matrix[x][y] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }

    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> res = new ArrayList<>();

        int left = 0,right = arr.length - 1;
        while(right - left >= k){
            if(Math.abs(arr[right] - x) >= Math.abs(arr[left] - x)){
                right--;
            }else{
                left++;
            }
        }
        for(int i = left;i <= right;i++){
            res.add(arr[i]);
        }
        return res;
    }


    public int search(int[] nums, int target) {
        int left = 0,right = nums.length - 1;
        int res = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                res = mid;
                break;
            }
            if(nums[mid] > nums[left]){
                if(nums[mid] > target){
                    if(nums[left] > target){
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[mid] > target){
                   right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return res;
    }

//    public boolean searchMatrix(int[][] matrix, int target) {
//        int m = matrix.length;
//        int n = matrix[0].length;
//
//        int top = 0,bottom = m - 1;
//        while(top <= bottom){
//            int mid = top + (bottom - top)/2;
//            if(matrix[mid][0] > target){
//                bottom = mid - 1;
//            }else{
//                top = mid + 1;
//            }
//        }
//
//        for(int i = top - 1;i >= 0;i--){
//            //if(matrix[i][0] > target)return false;
//            int left = 0,right = n - 1;
//            while(left <= right){
//                int mid = left + (right - left)/2;
//                if(matrix[i][mid] == target){
//                    return true;
//                } else if(matrix[i][mid] > target){
//                    right = mid - 1;
//                }else {
//                    left = mid + 1;
//                }
//            }
//        }
//        return false;
//    }
    public int maxProfit(int[] prices, int fee) {
        int profit = 0,minNum = prices[0];
        for(int i = 1;i < prices.length;i++){
            if(prices[i] < minNum){
                minNum = prices[i];
            }else if(prices[i] - minNum - fee > 0){
                profit += prices[i] - minNum - fee;
                minNum = prices[i] - fee;
            }
        }
        return profit;
    }


    public int findPeakElement(int[] nums) {
        int index = -1;
        int left = 0,right = nums.length - 1;
        if(nums[left] > nums[left + 1])return left;
        if(nums[right] > nums[right - 1])return right;
        while(left < right){
            left++;
            right--;
            if(nums[left] > nums[left + 1] && nums[left] > nums[left - 1])return left;
            if(nums[right] > nums[right - 1] && nums[right] > nums[right + 1])return right;
        }
        return index;
    }
    public int shortestSubarray(int[] nums, int k) {
        long[] preSum = new long[nums.length + 1];
        for(int i = 1;i <= nums.length;i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int minLength = Integer.MAX_VALUE;
        Deque<Integer> deque = new ArrayDeque<>();
        for(int i = 0;i <= nums.length;i++){
            while(!deque.isEmpty() && preSum[i] <= preSum[deque.peekLast()]){
                deque.pollLast();
            }
            while(!deque.isEmpty() && preSum[i] - preSum[deque.peekFirst()] >= k){
                minLength = Math.min(minLength,i - deque.peekFirst());
                deque.pollFirst();
            }
            deque.offer(i);
        }

        return minLength == Integer.MAX_VALUE ? -1 : minLength;
    }



    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int res = 0;
        int right = 0,left = 0;
        int product = 1;
        while(right < nums.length){
            product *= nums[right++];
            while(product >= k){
                product /= nums[left++];
            }
            res++;
        }
        for(int i = 0;i < nums.length;i++){
            if(nums[i] < k)res++;
        }
        return res;
    }
    public int characterReplacement(String s, int k) {
        int res = 0;
        char[] chars = new char[26];
        int right = 0,left = 0;
        int maxCount = 0;
        while(right < s.length()){
            char c = s.charAt(right);
            chars[c - 'A']++;
            maxCount = Math.max(maxCount,chars[c - 'A']);
            right++;
            while(right - left - maxCount > k){
                char d = s.charAt(left);
                chars[d - 'A']--;
                left++;
            }
            res = Math.max(res,right - left);
        }

        return res;
    }

    public int longestSubstring(String s, int k) {
        Map<Character,Integer> map = new HashMap<>();
        int res = 0;
        int right = 0,left = 0;
        while(right < s.length()){

        }
        return res;
    }

    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        TreeSet<Long> treeSet = new TreeSet<>();

        int right = 0,left = 0;
        while(right < nums.length){
            Long ceiling = treeSet.ceiling((long) nums[right] - (long) valueDiff);
            if(ceiling != null && ceiling <= ((long) nums[right] + (long) valueDiff)){
                return true;
            }
            treeSet.add((long) nums[right]);
            right++;
            if(right - left > indexDiff){
                treeSet.remove((long) nums[left]);
                left++;
            }
        }
        return false;
    }

    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if(k == 0)return false;
        HashSet<Integer> set = new HashSet<>();
        int left = 0,right = 0;
        while(right < nums.length){
            if(!set.contains(nums[right])){
                set.add(nums[right]);
            }else{
                return true;
            }
            right++;
            while(right - left >= k){
                set.remove(nums[left]);
                left++;
            }
        }
        return false;
    }

    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if(words.length == 0)return res;
        Map<String,Integer> need = new HashMap<>();
        for(String word : words){
            need.put(word,need.getOrDefault(word,0) + 1);
        }
        int n = s.length(), wordNum = words.length, wordLen = words[0].length();
        for(int i = 0;i < wordLen;i++){
            Map<String,Integer> window = new HashMap<>();
            int count = 0;
            for(int j = i;j + wordLen <= n;j += wordLen){
                if(j - i >= wordNum * wordLen) {
                    String word = s.substring(j - wordNum * wordLen,j - wordNum * wordLen + wordLen);
                    if(need.containsKey(word)){
                        if(window.get(word).equals(need.get(word))) count--;
                        window.put(word,window.get(word) - 1);
                    }
                }
                String word = s.substring(j, j + wordLen);
                if(need.containsKey(word)){
                    window.put(word,window.getOrDefault(word,0) + 1);
                    if(window.get(word).equals(need.get(word)))count++;
                }
                if(count == need.size())res.add(j - (wordNum - 1) * wordLen);
            }
        }
        return res;
    }

    public int minOperations(int[] nums, int x) {
        int res = Integer.MAX_VALUE;
        int sum = 0;
        for(int i = 0;i < nums.length;i++){
            sum += nums[i];
        }
        int right = 0,left = 0;
        int subSum = 0;
        while(right < nums.length){
            subSum += nums[right];
            right++;
            while(sum - subSum >= x){
                if(sum - subSum == x){
                    res = Math.min(res,right - left);
                }
                subSum -= nums[left];
                left++;
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }

    public String stringShift(String s, int[][] shift) {
        for(int[] commend : shift){

        }
        return null;
    }





}