# code11Proj

![alt text]()

Code-11 is a barcode system for encoding characters used primarily in labeling telecommunications equipment. The characters encoded are limited to digits 0 through 9, the dash (“–”), and a special start/stop character which appears at the beginning and end of each Code-11 barcode.

Code-11 is a discrete system, and each character is encoded independently. A character’s encoding is represented by five adjacent regions, or bars, that alternate between a dark color and a light color, starting with a dark bar. The width of each bar is either narrow or wide, according to the encoding scheme shown below, where 0 represents a narrow bar and 1 represents a wide bar.

Thus the character 1 is encoded as a wide dark bar, a narrow light bar, a narrow dark bar, a wide light bar, and finally a narrow dark bar. The barcodes for the individual characters must be separated by a narrow light bar whose only function is to separate the characters.
A two-width encoding like that used for Code-11 has the benefit of simplicity. Since it is necessary only to distinguish a narrow bar from a wide bar, Code-11 allows for a large level of print tolerance in lower-quality printing conditions.
To enable detection of errors, the Code-11 barcodes we use will have two check characters, C and K, added at the end of the message (before the stop character). If the n characters to be encoded (left to right) are c1 through cn, then the weight of the C check character is



where w(ci) is the weight associated with character ci. The weights for the digits 0 through 9 are 0 through 9; the weight for the hyphen is 10. Note that %(mod) has higher precedence than +.

The weight of the K check character is
