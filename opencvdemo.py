from cv2.cv import *

img = LoadImage("/home/gaurav/imageprocessing/priyanka.jpg")
NamedWindow("opencv")
ShowImage("opencv",img)
WaitKey(0)
