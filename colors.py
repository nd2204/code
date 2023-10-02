import json
import re

def Hex2RGB(hexvalue):
    RGB = {}
    pattern = r'#?([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})'
    match = re.search(pattern, hexvalue)

    if match:
        RGB["r"] = int(match.group(1), 16)
        RGB["g"] = int(match.group(2), 16)
        RGB["b"] = int(match.group(3), 16)
        return RGB
    else:
        return None

def find_biggest_before(dictRGB, targetRGB, channel):
    biggest_before = None
    for row in dictRGB:
        currentValues = row["rgb"][channel]
        if (currentValues < targetRGB[channel]): 
            if biggest_before is None or biggest_before < currentValues:
                biggest_before = row["rgb"][channel]
    return biggest_before

def find_smallest_after(dictRGB, targetRGB, channel):
    smallest_after = None
    for row in dictRGB:
        currentValues = row["rgb"][channel]
        if (currentValues > targetRGB[channel]): 
            if smallest_after is None or smallest_after > currentValues:
                smallest_after = currentValues
    return smallest_after

def search(dictRGB, targetRGB):
    before = []
    after = []
    for channel in ['r', 'g', 'b']:
        targetChannelAfter = []
        targetChannelBefore = []
        if channel == 'r':
            targetChannelAfter = find_smallest_after(dictRGB, targetRGB, channel)
            targetChannelBefore = find_biggest_before(dictRGB, targetRGB, channel)
        else:
            targetChannelAfter = find_smallest_after(after, targetRGB, channel)
            targetChannelBefore = find_biggest_before(before, targetRGB, channel)
        print(channel)
        print(targetChannelBefore)
        print(targetChannelAfter)
        for row in dictRGB:
            currentChannel = row["rgb"][channel]
            if currentChannel == targetChannelBefore:
                before.append(row)
            if currentChannel == targetChannelAfter:
                after.append(row)
    return [
        {"before": before},
        {"after": after}
    ]


if __name__ == "__main__":
    inputRGB = input("Paste color: ")
    channels = Hex2RGB(inputRGB)
    with open("256-colors.json", "r") as file:
        data = json.load(file)
        # print(data)
        print(channels)
        result = search(data, channels)
        for row in result:
            print(row)
