# soundex

(1) 保留第一个字母。丢掉所有出现的a、e、i、o、 u、y、h、w。
(2) 以数字来代替辅音（第一个字母除外）：
- b、f、p、v : 1
- c、g、j、k、q、s、x、z : 2
- d、t : 3
- l : 4
- m、n : 5
- r : 6

(3) 如果相邻字母编码相同，用一个数字表示它们即可。同样，如果出现两个编码相同的字
母，且它们被h或w隔开，也这样处理；但如果被元音隔开，就要编码两次。这条规则同样适用
于第一个字母。
(4) 当得到一个字母和三个数字时，停止处理。如果需要，补零以对齐。

1. Retain the first letter. Drop all other occurrences of a, e, i, o, u, y, h, w.
2. Replace consonants with digits (after the first letter):
    • b, f, p, v: 1
    • c, g, j, k, q, s, x, z: 2
    • d, t : 3
    • l: 4
    • m, n: 5
    • r: 6
3. If two adjacent letters encode to the same number, encode them instead as a single number.
Also, do so if two letters with the same number are separated by h or w (but code them twice if separated by a vowel).
This rule also applies to the first letter.
4. Stop when you have a letter and three digits. Zero-pad if needed.
