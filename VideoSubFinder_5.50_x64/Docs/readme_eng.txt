
#########################################################################################################
About Program
#########################################################################################################

The main purpose of this program is to provide functionality for extract hardcoded text (hardsub) from video.

It provides two main features:
1) Autodetection of frames with hardcoded text (hardsub) on video with saving info about timing positions.
2) Generation of cleared from background text images, which allows with usage of OCR programs (like FineReader or Subtitle Edit) to generate complete subtitle with original text and timing.

For working of this program will be required "Microsoft Visual C++ Redistributable for Visual Studio 2015, 2017 and 2019": https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads
x64: https://aka.ms/vs/16/release/vc_redist.x64.exe
x86: https://aka.ms/vs/16/release/vc_redist.x86.exe
Latest versions were built and tested on: Windows 10

#########################################################################################################
Quick Start Guide
#########################################################################################################
How to use without deep details:
1) Click in menu "File->Open Video" (any variant, but OpenCV has better accuracy)
2) Check boundary box in "Video Box" where most subs will appear (you can move split lines for that in it): by default it is whole video.
It is recommended to reduce area for search for getting less wrong detections and less timings splits.
3) Check what horizontal alignment subtitles has on video relatively to selected boundary box "Center/Left/Right/Any" and set related value in "Text Alignment" property in "Settings" tab.
Center - is in most case, so it set by default.
4) It is strongly recommended to use "Use Filter Colors" but you can skip this step.
For this you need:
* - scroll video to subtitle frame
* - press 'U' in Video Box and select subtitle pixel by 'Left Mouse' click
* - copy Lab color record from right bottom part in "Settings" tab to "Use Filter Colors" in left top side of "Settings" tab
* - if there are may subtitles with different colors you can add all of them to "Use Filter Colors" by adding new line records with "Ctrl+Enter"
5) Click "Run Search" in the first tab page (if you need to get only timing and original images with potential subs go after this step to the last tab page and press "Create Empty Sub")
6) Check ILA Images: subtitles symbols by default will be searched inside white pixels in ILA images, if white pixels in ILA images will not contain some symbols or they are broken, 
this is possible if you use too strong Color Filters or subtitles pop-up on video, in this case it is better to change program settings or delete such ILA Images.
7) [MOST IMPORTANT PART IF YOU DONT USE COLOR FILTERING]
Before continue: Check does subtitles has darker border color then subtitles text color.
In most case it is so, if not than disable checkbox "Characters Border Is Darker" in first right setting in "Settings tab".
In most cases program correctly identify which color is related to subtitles text but in some cases it is too complicated, in such cases decision will be applied according this setting.
8) If you are using "Use Filter Colors" and have too good ILAImages (all characters separated from background)
it is recommended to turn on "Use ILAImages for getting TXT symbols areas" which can reduce amount of garbage.
9) Click "Create Cleared TXTImages" on the last tab page (for get Text Mining, if you plan to OCR text after in other software)

Video instructions:
There are many instructions which can be found in youtube and was made by this program users.
One of most recommended by them are:
https://www.youtube.com/watch?v=Cd36qODmYF8
https://www.youtube.com/watch?v=VHsUfqqAkWY&t=124s

#########################################################################################################
Known Issues
#########################################################################################################

1) Different timing in OpenCV vs FFMPEG video open but now they are very close with difference ~ 000-001 milliseconds.
2) In case of Center alignment, which is by default, take into the note that if whole subtitle will be in right half part of selected boundary box it will be removed.

#########################################################################################################
Recommended Settings And Some Solutions For "Run Search" and "Create Cleared TXTImages"
#########################################################################################################

1) For getting best results during "Run Search" and "Create Cleared TXTImages":
--------------------------------
1-1) Before starting "Run Search":
--------------------------------
After opening video:
*) Test all setting in "Settings" tab by pressing "Test" button with selection different video frames with too light and to dark background and so on.
*) Check boundary box in "Video Box" where most subs will appear (you can move split lines for that in it): by default it is whole video.
It is recommended to reduce area for search for getting less wrong detections and less timings splits.
In worse cases, you can detect each line separately by running program multiple times with different video area selection (this can fix
possible incorrect multiple lines subtitles splits in single frame)
*) Check what horizontal alignment subtitles has on video relatively to selected boundary box "Center/Left/Right/Any" and set related value in "Text Alignment" property in "Settings" tab.
alignment: Center - is in most case, so it set by default. Take into the note that if whole subtitle will be in right half part of selected boundary box it will be removed.
alignment: Any - currently supported but not so good as other types.
*) For decrease amount of: wrong timing splits during Run Search, wrong produced timings, not detected subtitles, missed multiple lines during Clean TXT Images on found images with subs;
you can do next - adopt: "Moderate Threshold"(moderate_threshold)(located in "Settings" tab in left panel) in range [0.25, 0.6] by "Test" button
Need to find optimal value when subtitles symbols in 'After First/Second/Third Filtration' images will have not broken edgings and
filled with white (not empty) but most part of background disappear, it very depends from video and also from concrete frame,
so try on too bright and dark scenes and so on. Then higher value than more pixels will be filtered/removed as not related to subtitle.
0.25 - are working on most videos, especially in case with 1080p, but can produce too much of garbage.
0.5-0.6 - very oftenly optimal in case of subtitles with low resolution (~480p) and solid outlines/borders (like white subs with black outlines).
0.1 - in some cases when subtitles have not outlines or/and transparent (but many splits also as garbage can be found).
*) It is recommended to set "Use Filter Colors" which can very improve accuracy of results:
more accurate produced timing, less wrong splits and better cleared TXT images results (read below in separate topic).
*) Also on splits affects two parameters:
vedges_points_line_error = 0.3
ila_points_line_error = 0.3
0.3 is like 30% allowed difference in other case nearest by time two subtitles treated as different.
Then higher values than more rarely time code will be split.
Then lover values than more often time code will be split.
I don't recommend to change them. Only if you sure that there is not sequential subtitles in video (which come without pause between them) you can try to increase them.
-------------------------------------------
1-2) Before starting "Create Cleared TXTImages":
-------------------------------------------
*) Test all setting in "Settings" tab by pressing "Test" button with selection different video frames with too light and to dark background and so on.
*) Check does subtitles has darker border color then subtitles text color (in most case it is so,
if not than disable checkbox "Characters Border Is Darker" in first right setting in "Settings tab")
In most cases program correctly identify which color is related to subtitles text but in some cases it is too complicated,
in such cases decision will be applied according this setting.
*) Check on missed symbols during clearing images or selected video frame
Moderate Threshold For Scaled Image (moderate_threshold_for_scaled_image)(located in "Settings" tab in right panel) [0.1, moderate_threshold]
0.25 will be working in most case, if some symbols are removed try to use lover values or else.
It should be not higher then optimal value for moderate_threshold.
In some cases when subtitles have bad/missed borders (outline color) and have mostly same color as background
(can be difficultly separated from background) it need to be set to 0.1 or 0.15, also in such cases is recommended
to turn on "Use ILAImages before clear TXT images from borders", it can improve results.
*) It is recommended to set "Use Filter Colors" which can very improve accuracy of results:
more accurate produced timing, less wrong splits and better cleared TXT images results (read below in separate topic).
*) If you are using "Use Outline Filter Colors" or have too good ILAImages (all characters separated from background)
it is recommended to turn on "Use ILAImages for getting TXT symbols areas" which can reduce amount of garbage.
*) For decrease amount of garbage on cleaned TXT images you can try to turn on "Clear Images Logical" (located in "Settings" tab in right panel) which is turned off by default.
This option can remove garbage but can remove wrong/good elements. It try to remove figures which mostly appear inside other figures and so on.
Mostly useful if everything listed below is right:
* - language is not Hieroglyph or Arabic type
* - symbols are not broken in produced results (subtitles are with good quality, with stable luminance)
* - "Use Outline Filter Colors" is used (subtitles has solid outlines from all sides)
* - "Use ILAImages for getting TXT symbols areas" turned on
*) For decrease amount of garbage on cleaned TXT images you can also try to turn on "Remove too wide symbols"
Don't use it for Arabic or handwritten subs which can have very long symbols or can be written not separately.

2) "Use Filter Colors" and/or "Use Outline Filter Colors"
It is strongly recommended to use "Use Filter Colors" which can very improve accuracy of results,
more accurate produced timing, less wrong splits and better cleared TXT images results.
Color filters are used in both cases "Run Search" and "Clear TXT Images" so use them accurately.
You can define multiple colors ranges if subtitles has different colors during video (by usage "Ctrl+Enter" for adding new line record)
For this you need:
* - scroll video to subtitle frame
* - press 'U' in Video Box and select subtitle pixel by 'Left Mouse' click
* - copy Lab color record from right bottom part in "Settings" tab to "Use Filter Colors" in left top side of "Settings" tab
* - if there are may subtitles with different colors you can add all of them to "Use Filter Colors" by adding new line records with "Ctrl+Enter"
*) Use not too strong color filtering if subtitles are mostly stable and have same colors: 
"Use Filter Colors" - inline color - color of subtitles symbols, located in "Settings" tab in left panel.
Example of values which are working in most case of white subtitles:
Lab: l:100-255 a:0-255 b:0-255

Lab: l:180-255 a:108-148 b:108-148  (mostly working in all cases)
Lab: l:200-255 a:118-138 b:118-138
Lab: l:220-255 a:118-138 b:118-138 (strong color filter, mostly useful only in case if subs which has very good quality)
Format of data:
Lab: l:l_val a:a_val b:b_lab_val
Lab: l:min_l_val-max_l_val a:min_a_val-max_a_val b:min_b_lab_val-max_b_lab_val
RGB: r:min_r_val-max_r_val g:min_g_val-max_g_val b:min_b_val-max_b_val
RGB: r:r_val g:g_val b:b_val L:l_val
RGB: r:r_val g:g_val b:b_val L:min_l_val-max_l_val
-----
Lab - is color space https://en.wikipedia.org/wiki/CIELAB_color_space
Lab is most preferred color filtering format (CIELAB is designed to approximate human vision)
L - is more like luminance.
when 'a' and 'b' like chroma components.
-----
if min_l_val==max_l_val or only l_val is specified then will be used dL value from settings for define 'L'/'l' range: [l_val-dL, l_val+dL]
if min_a_val==max_a_val or only a_val is specified then will be used dA value from settings for define 'a' range: [a_val-dA, a_val+dA]
if min_b_lab_val==max_b_lab_val or only b_lab_val is specified then will be used dB value from settings for define 'b' range: [b_lab_val-dB, b_lab_val+dB]
*) Use not too strong "Use Outline Filter Colors" only if all symbols are contained inside borders:
subtitles has solid outlines from all sides, symbols are contained in inside figures produced by pixels which are in outline filter colors range.
"Use Outline Filter Colors" - outline color - color of symbols borders, located in "Settings" tab in left panel.
Example in case if borders are mostly black color.
Lab: l:0-30 a:0-255 b:0-255
*) Find optimal values for color filters by using 'T' button in Video Box
Press left/right/space for check that during video symbols are shown stable (not broken), check on different scenes.
* - all pixels which are in inline color filters will be shown as 'red' (pixels related to searched symbols)
* - all pixels which are in outline color filters will be shown as 'green' (pixels related to searched symbols borders)
* - all pixels which are in inline and outline color filters will be shown as 'yelow' (better that no one will be in yelow (no intersection))
Also:
Using 'U' button in Video Box will show original video frame but in full screen.
Using 'Y' button in Video Box will show pixels related to inline color without change, all others in black color.
Using 'I' button in Video Box will show pixels related to outline color without change, all others in black color.
You can get pixel color by left mouse click in Video box or in shown full screen image (its values and color will be shown in "Settings" tab in bottom right part)
*) If you are using "Use Outline Filter Colors" or have too good ILAImages (all characters separated from background)
it is recommended to turn on "Use ILAImages for getting TXT symbols areas" which can reduce amount of garbage.

3) "Create Cleared TXTImages" from subs with bad quality:
3-1)
In case of subs with bad quality, especially in case of not too stable luminance in text color:
You can try to turn on "Extend By Grey Color" in "Settings" tab, which turn on usage of "Allow Min Luminance" setting.
In this case you should manually specify optimal value in "Allow Min Luminance" for you video.
It is also useful if you use "Use Filter Colors", in this case is recommended to set value in "Allow Min Luminance" same as min_l_val in "Use Filter Colors".
"Extend By Grey Color" extend text area by pixels whose chroma color is same as automatically detected but luminance is in range:
[min("Allow Min Luminance", min_text_lum_auto_detected), max_text_lum_auto_detected]
Also you can change "Video Gamma" or/and "Video Contrast" in "Settings" tab, which can also very improve results.
In some cases setting "Video Gamma" == 0.7 and setting "Allow Min Luminance" == 100 with turned on "Extend By Grey Color" produce more better results.
For find optimal values for your video you can use "Test" button in "Settings" tab.
3-2)
In case of subs with bad quality sometimes help if improve RGBImages quality by using "Topaz Gigapixel AI": https://topazlabs.com/gigapixel-ai/
Take into the note that most settings for "Create Cleared TXTImages" are aligned with RGBImages resolution 480-720p.
So now only x2 scale is most recommended setting in "Topaz Gigapixel AI" and which is default in it.
To use this approach: you need to replace original RGB images generated by "Run Search" by produced in "Topaz Gigapixel AI",
they should have same names as original generated by "Run Search".

4) "Create Cleared TXTImages" from subs with no outlines/borders:
In case if subtitles have not outlines/borders there possible cases when symbols become inseparable from background,
in this case sometimes can very help to turn on "Use ILAImages before clear TXT images from borders" in "Settings" tab,
and at same time it is recommended to set most close/strong "Use Filter Colors" range,
in this case, especially if background dynamically changed, produced ILA images can possibly very help to separate symbols from background.
Also on such video fragments and images can help:
"Min Sum Color Difference": min_sum_color_diff = 0 (with selection boundary box in "Video Box" where to search subtitles)
"Moderate Threshold": moderate_threshold = 0.1
"Moderate Threshold For Scaled Image": moderate_threshold_for_scaled_image = 0.1
"Use ILAImages for getting TXT symbols areas" - Turn Off: use_ILA_images_for_getting_txt_symbols_areas = 0 (which is by default)

5) "Create Cleared TXTImages" from subs with multiple colors in single subtitle line:
There possible cases when in single subtitle line part of symbols has one color when other symbols has another,
for example left part of subtitle line is with one color and right part with another.
In this case you can use "Use Filter Colors" with define all of used colors in subtitle and turn on "Combine To Single Cluster" in "Settings" tab.

6) Add Video Filters during "Run Search"
6-1)
In case of logo present or some other issues program now support also AviSynth+ scripts by opening video with FFPMEG CPU device video decoding:
https://github.com/AviSynth/AviSynthPlus/releases/download/v3.6.1/AviSynthPlus_3.6.1_20200619.exe
NOTE1: HW Acceleration (GPU) doesn't support AviSynth. So you need to set CPU device in "FFMPEG HW Devices" in "Settings" tab (which is by default).
NOTE2: It will not work if use DirectShowSource, in this case decoded frames will be broken. For open video is recommended to use 
FFmpegSource or LSMASHSource plugin usage in which it was tested and worked without issues.
Examples of avs scripts for DeLogo purpose you can find in:
https://sourceforge.net/p/videosubfinder/discussion/684990/thread/bddff843f5/?page=2
Tested with AviSynth plugins:
FFmpegSource plugin v2.40: https://github.com/FFMS/ffms2/releases/tag/2.40
LSMASHSource plugin 20200728 : https://github.com/HolyWu/L-SMASH-Works/releases/tag/20200728
MaskTools2 v2.2.26: https://github.com/pinterf/masktools/releases/tag/2.2.26
All AviSynth plugins can be found in: http://avisynth.nl/index.php/AviSynth%2B_x64_plugins
NOTE3: Plugins dll should be placed to "C:\Program Files (x86)\AviSynth+\plugins64+"
NOTE4: LSmashVideoSource failed to open mkv but FFVideoSource open it successfully in my case.
6-2)
You can also use FFMPEG Video Filters by opening video with FFMPEG video decoding.
https://ffmpeg.org/ffmpeg-filters.html#Video-Filters
You can set them in "Settings" tab by setting "FFMPEG Video Filters" record.
For example you can set it to: curves=psfile='curves.acv'
for using Photoshop curves file (.acv) for specify color settings changes.

7) Performance during "Create Cleared TXTImages":
Currently program use:
"CPU kmeans initial loop iterations" == 20
CPU kmeans loop iterations" = 30
This is required in case of subs which don't have good borders, in such cases can be too complex to separate text from background.
In case of subs with solid/good borders you can try to decrease both of them to 10, this will increase performance ~x2.
Dependently from what CPU and Nvidia GPU you have, if speed is important it is recommended to turn on "Use CUDA GPU Acceleration" checkbox,
this can also increase performance ~x2.

#########################################################################################################
Used terms:
#########################################################################################################

*) ISAImages - Intersected Subtitles Areas (by multiframe usage)
*) ILAImages - Intersected Luminance Areas (by multiframe usage), the areas where pixels are not change too much in luminance in range:
"Max luminance diff from down for IL image generation"
"Max luminance diff from up for IL image generation"
First image of DL sequence (~12 nearest frames in video) are taked as reference, all next images in DL sequence are compared with it by luminance change.
On produced ILAImages also affect "Use Filter Colors" and "Use Outline Filter Colors" which are applied on each frame and intersected with reference (First image of DL sequence).

#########################################################################################################
For OCR (conversion of images of text into machine-encoded text) can be used:
#########################################################################################################

(1) FineReader: https://www.abbyy.com/finereader/
1_1. Video instructions:
https://www.youtube.com/watch?v=Cd36qODmYF8
https://www.youtube.com/watch?v=VHsUfqqAkWY&t=124s

#-----------------------------------------------------

(2) Subtitle Edit (Free software): https://www.videohelp.com/software/Subtitle-Edit
NOTE: The instruction below was tested on 3.5.16 version with images with English and Croatian (Tesseract 3.02) Text and it works
In VideoSubFinder:
2_1_1. Click in menu "File->Open Video" (any variant: FFMPEG variant give better performance if use top GPU and video has 720p or higher resolution)
2_1_2. Click "Run Search" and get images (in the first tab page: "Search").
2_1_3. Click "Create Cleared TXTImages" (in the last tab page: "Search").
2_1_4. [Note: This step can be skipped] Open "TXTImages" folder and remove images without text.
2_1_5. Click "Create Empty Sub From Cleared TXTImages" which will generate "sub.srt" file with timing only (in the last tab page: "Search").
In Subtitle Edit:
2_2_1. Click in menu "File->Open" and select sub.srt file
2_2_2. Click in menu "File->Import images.." + Click "..." in top right and select all files in "TXTImages" (CTRL+A)
2_2_3. IMPORTANT_PART: Select all records in "Subtitle text" tree (select any record and press CTRL+A), right mouse click, select "Image preprocessing...",
select check box with "Invert colors", press "OK"
2_2_4. Select "OCR Method" (any Tesseract method works good on English Text)
2_2_5. Select Right "Language" also as it in Dictionary and download it by pressing "..." and "Download"
2_2_6. press "Start OCR" and press "OK" at the end if results are good.
2_2_7. Click in menu "File->Save as..." res.srt and press "Save"

One of recomended articles by Subtitle Edit users:
https://digitalaladore.wordpress.com/2014/11/17/using-tesseract-via-command-line/

#-----------------------------------------------------

#########################################################################################################
OUTDATED OLD INFORMATION:
#########################################################################################################

How to use in details:
1) Run VideoSubFinder.exe

2) In the menu select File-> Open Video, select the video file in which
   it is necessary to find sabies (avi, mpeg, mpg, asf, asx, wmv, ...)
   A video of the current video will appear in the Video Box.

3) You can immediately press Run (by default at the moment you must be in
   the Search tab), only the current time will be displayed in the Video Box
   processed frame (with a frequency of 1 times per second), if at the moment
   will be found at least one sub, then its image will be displayed in Image
   Box, the search results are dropped into the RGBImages folders (the original screens from
   video) and ISAImages (Intersected Subtitles Areas (by multiframe usage)), make sure that
   you had at least 100 mb of free disk space.

4) You can set the start and end time of the search for sabs, for this use
   key keys ctrl + z and ctrl + x (or through the menu Edit -> ...)
   Use the slider in the Video Box to navigate through the video :),
   for frame-by-frame navigation on video (use the arrows <-, ->, Up, Down
   or mouse wheel).

5) You can reduce the detection area by moving the vertical and horizontal
   Separating lines in the VideoBox with the mouse.

5) You can check the partially current settings:
   go to the Settings tab, move to any frame of the video (where available
   or there is no text), press the Test key (if there is text on the frame,
   Image Box should appear not an empty image processing result, otherwise
   black screen (but not necessary)) If the result of image processing with
   text is empty then it makes sense to loosen the settings (namely, most likely it will be
   it is enough to reduce Sum Color Difference and Sum Multiple Color Difference both
   on 600 or 500 or 400). The result of pressing the Test button is three
   After After Filtration, After Second Filtration, VEdgesPointsImage
   they can be viewed by clicking the buttons in the left and in the right above the Test button,
   and also in the TSTImages folder.
   
   "After First Filtration" is the resulting image as a result
   initial processing of the frame, the result of the processing is affected by all the "Settings for
   Operators Sobel "except one H-Vertical Threshold, all" Settings For
   Color Filter "except for one Sum Multiple Color Diff.
   
   "After Second Filtration" is the resulting image as a result
   secondary image processing (processing applied to the image
   resulting from "After First Filtration"), the result of processing
   affect all the "Settings for Linear Filtering", all "Settings for Points
   Color Borders ", all" Settings for Color Filter "except one
   Sum Color Diff.
 
   "VEdgesPointsImage" is translated as an image obtained from points
   vertical color boundaries. This image is obtained by converting
   frame into a black and white image, then applying a horizontal
   operator Sobel to determine the strength of the color difference. Then by threshold
   Filtering (all points whose strength is lower than the threshold set in the settings
   "H-Vertical Threshold" is replaced with black or white). These images
   Are used when checking whether adjacent frames with identical text or
   no)


6) At the end of the search for the sub it is desirable to go to the folder RGBImages and delete all
   those frames that are dummy, then on these images you can
   create an empty sub with timings, go to the OCR tab and click
   on Create Empty Sub, and there is the possibility of extending the sub by
   setting the "Min Sub Duration" value of the minimum duration of the sub
   seconds, and a logical attempt will be made to extend the sub
   by changing the time it ends.

More about settings:

Moderate Threshold - by means of complex operators from the source frame (when
   use of primary processing) the result is an image where
   Each point of the original frame is correlated with its strength (the strength of the color difference),
   and averaged so that in the region of the bright text and the pale text of force
   the color difference will not be too much different. Then on this
   image is the maximum strength of the color difference, this value
   multiplied by "Moderate Threshold", all points of power below the received
   The quantities are replaced by black or white.

H-Vertical Threshold - described in step 5 of "VEdgesPointsImage".

Line Height - used in algorithms to reduce the detection area, as well as
   linear filtration. The whole image is divided into horizontal lines
   thickness (height) "Line Height". Then each of these lines is analyzed in
   isolation.

Between Text Distance - is used for secondary image processing. How are you
   already had to understand the result of the primary processing, we get a binary
   image (speaking in simpler words consisting of points with only two
   possible colors black and white). This image is broken
   On the thickness line "Line Height". In each of these lines, blocks are searched for
   (presumably textual), by the principle if in the next column of height
   "Line Height" is at least one white point then the block has not yet ended. Then
   It looks like the distance between all the blocks found, it should not exceed
   The width of the video frame is multiplied by "Between Text Distance". If more then
   The block whose center is farthest from the center of the frame is deleted.

Text Center Offset-as a result of the above-described "From Text Distance"
   in each line there remains some possibly zero number of blocks. For these
   blocks (presumably a text string) is their center. If
   center is offset by more than "Text Center Offset" * ("video frame width" / 2) from
   center of the frame, then the block is removed most shifted from the center and so on until
   until the condition is satisfied. An important point is still what is being checked
   the location of the blocks in both halves of the image, otherwise all the blocks are deleted.

Min Points Number - in all remaining blocks in the line (read above)
   the number of white dots is counted if their number is less than the "Min Points Number" then
   all blocks in the line are deleted.

Min Points Density - the total area of ​​the remaining blocks in the row is counted
   (= SS) (read above), as well as the total number of white points in them (= S).
   It is checked that S / SS> = "Min Points Density", if not all of these
   blocks are deleted.

Segment Width - used in algorithms to reduce the detection area, and
   also in color filtration in secondary processing. Each line is divided into
   blocks of equal length "Segment Width" (not to be confused with those described above).

Min Segments Count - used in algorithms to reduce the detection area,
   as well as in color filtration in secondary processing. Minimum number
   neighboring blocks with sufficiently high color gradients at which
   The line containing them remains (will) be considered a supposedly textual
   (text-containing).

Sum Color Difference - used at the very beginning of the initial processing for
   reducing the detection area. The original video frame is split on the line
   thickness 1, each line is divided into blocks of equal width "Segment Width".
   In each block, the total color difference of neighboring points is calculated, if
   in the line are "Min Segments Count" of neighboring blocks with "swings"> = "Sum
   Color Difference ", then the line is assumed to be text-containing.

Min Sum Multiple Color Diff - used at the end of the secondary processing. How are you
   should still remember at the end of the secondary processing we possibly have in any of the
   line "Line Height" still left some blocks
   (potentially text-containing blocks). The whole area from their beginning to the end
   is divided into blocks of width "Segment Width". In each line (such lines
   will be "Line Height") of each such block is calculated by the
   differential. If in each line of any block of the "difference"> = "Sum Multiple
   Color Diff ", then such a block is considered potentially text containing.
   If as a result in this area there are "Min Segments Count" of such
   neighboring blocks, then the entire line is assumed to be text-based.

OCR Settings

Clear Images Logical (Remove Garbage) - performe cleaned image analyzes on present symbols and garbage.
	In case of turned off it will not try to remove potential garbage on cleaned images,
	sometimes this produce better results.

Sub Frames Length - the minimum duration of the sub.

Sub Square Error - in fact, the first detection of the sub goes as follows,
   found the first frame potentially containing the text, then if not less than "Sub
   Frames Length "including its frames are also potentially
   text-containing and the area of ​​their potentially text-based areas does not differ
   more than on "Sub Square Error" it is considered that the sub is found (further there is a test
   for the presence of the text string, if the test did not fail, then the search for the end of the sub is going on,
   matching identical sabs).

VEdgesPoints line error - used for stitching sabas, as well as detecting
   end of the sub. Neighboring frames are compared by the area of ​​points of vertical
   color boundaries in potentially text areas. If the areas differ
   no more than "VEdgesPoints line error" then it is considered that the end of the sub is not yet
   found.

Text Procent - used in the test for the presence of a text string. Looking for at least
   one line of thickness "Line Height" in which the sum of all lengths potentially
   text blocks in relation to the extent of the area on which they are
   are located> = "Text Procent". Also checks that this amount should be> =
   "Min Text Length" * "Video frame width".

Note:
A long search time is due to the fact that text detection is used
very complex and time-consuming algorithms developed by the Chinese (whose articles I
studied and implemented in this program), namely, the main used
(studied) works:

1) "A NEW APPROACH FOR FOR VIDEO TEXT DETECTION"
   Min Cai, Jiqiang Song, and Michael R. Lyu,
   Department of Computer Science & Engineering
   The Chinese University of Hong Kong Hong Kong SAR, China

2) Automatic Image Segmentation by Integrating Color-Edge Extraction
   and Seeded Region Growing 2001.
   Jianping Fan, David. K. Y. Yau, Member, IEEE, Ahmed. K. Elmagarmid,
   Senior Member, IEEE, and Walid G. Aref, Member, IEEE
 
3) Automatic Location of Text in Video Frames.
   Xian-Sheng Hua, Xiang-Rong Chen, Liu Wenyin, Hong-Jiang Zhang
   Microsoft Research China

4) EFFICIENT VIDEO TEXT RECOGNITION USING MULTIPLE FRAME INTEGRATION
   Xian-Sheng Hua, Pei Yin, Hong-Jiang Zhang
   Microsoft Research Asia, Dept. of Computer Science and Technology,
   Tsinghua Univ.

Also, the principle invented by Shalcker was partially used to
Reduce the video processing area on each frame.

In the first place, I first invented and implemented multi-frame
processing and linear filtering of processed frames, as well as some
improvement and modification of algorithms from the above listed works and their
implementation.