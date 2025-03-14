; =================================================================================================
; WeatherComJSONPollen.inc by JSMorley
; "Weather.com - Parsing the JSON" (https://forum.rainmeter.net/viewtopic.php?f=118&t=34628)
;
; Requires that WeatherComJSONVariables.inc be @Included in the skin before this file.
;
; Updated August 4, 2020
; ==================================================================================================

[@PollenSuperParent]
Measure=WebParser
URL=https://api.weather.com/v2/indices/pollen/daypart/15day?geocode=#Latitude#,#Longitude#&language=#Language#&format=json&apiKey=#APIKey#
UpdateRate=#UpdateRate#
Flags=Resync | NoCookies
UserAgent=#UserAgent#
LogSubstringErrors=0
StringIndex=1
RegExp=(?siU)^(.*)$
FinishAction=[!EnableMeasureGroup Parents]

; ====================================================
; Create Parent measures for the various data elements
; ====================================================

[@PollenValidDateStampsParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"fcstValidLocal":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]
FinishAction=[!EnableMeasureGroup Times]

[@PollenDayPartIndicatorParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"dayInd":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]
FinishAction=[!EnableMeasureGroup Times]

[@PollenDayPartNameParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"daypartName":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]

[@PollenGrassIndexParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"grassPollenIndex":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]

[@PollenGrassCategoryParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"grassPollenCategory":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]

[@PollenTreeIndexParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"treePollenIndex":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]

[@PollenTreeCategoryParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"treePollenCategory":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]
[@PollenRagweedIndexParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"ragweedPollenIndex":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]

[@PollenRagweedCategoryParent]
Measure=WebParser
Group=Parents
Disabled=1
URL=[@PollenSuperParent]
RegExp=(?siU)"ragweedPollenCategory":\[(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)[,|\]]

; ====================================================
; Part 1
; ====================================================

[@PollenPart1ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart1ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart1DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart1RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 2
; ====================================================

[@PollenPart2ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart2ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart2DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart2RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 3
; ====================================================

[@PollenPart3ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart3ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart3DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart3RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 4
; ====================================================

[@PollenPart4ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart4ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart4DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart4RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 5
; ====================================================

[@PollenPart5ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart5ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart5DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart5RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 6
; ====================================================

[@PollenPart6ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart6ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart6DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart6RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 7
; ====================================================

[@PollenPart7ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart7ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart7DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart7RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 8
; ====================================================

[@PollenPart8ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart8ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart8DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart8RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 9
; ====================================================

[@PollenPart9ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart9ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart9DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart9RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 10
; ====================================================

[@PollenPart10ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart10ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart10DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart10RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ====================================================
; Part 11
; ====================================================

[@PollenPart11ValidDateStamp]
Measure=WebParser
URL=[@PollenValidDateStampsParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11ValidWeekDay]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@PollenPart11ValidDateStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
FormatLocale=#Language#
Format=%A

[@PollenPart11DayPartIndicator]
Measure=WebParser
URL=[@PollenDayPartIndicatorParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11DayPartName]
Measure=WebParser
URL=[@PollenDayPartNameParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11GrassIndex]
Measure=WebParser
URL=[@PollenGrassIndexParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11GrassCategory]
Measure=WebParser
URL=[@PollenGrassCategoryParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11TreeIndex]
Measure=WebParser
URL=[@PollenTreeIndexParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11TreeCategory]
Measure=WebParser
URL=[@PollenTreeCategoryParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11RagweedIndex]
Measure=WebParser
URL=[@PollenRagweedIndexParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@PollenPart11RagweedCategory]
Measure=WebParser
URL=[@PollenRagweedCategoryParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#
