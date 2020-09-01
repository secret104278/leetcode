/*
 * @lc app=leetcode id=11 lang=golang
 *
 * [11] Container With Most Water
 */

/*
直覺想到是 two pointer。
A(i,j) = min(i,j) * (j-i)
考慮兩個維度：高度(y) / 寬度 (x)
以 monotone 為出發，從最寬的兩邊開始找，從左邊和右邊找到最高的

awesome explaination:
https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
*/

// @lc code=start
func maxArea(height []int) int {

	left := 0
	right := len(height) - 1
	maxArea := 0

	for {
		if left >= right {
			break
		}

		dist := right - left
		lowest := 0
		if height[left] > height[right] {
			lowest = height[right]
			right--
		} else {
			lowest = height[left]
			left++
		}

		area := lowest * dist
		if area > maxArea {
			maxArea = area
		}
	}

	return maxArea
}

// @lc code=end

