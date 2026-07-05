def generatePermutations(numbers, currentPermutation, usedNumbers):
    if len(currentPermutation) == len(numbers):
        print(" ".join(str(number) for number in currentPermutation))
        return

    for number in numbers:
        if number not in usedNumbers:
            usedNumbers.add(number)
            currentPermutation.append(number)
            generatePermutations(numbers, currentPermutation, usedNumbers)
            currentPermutation.pop()
            usedNumbers.remove(number)


def generateSubsetsBySize(numbers, startIndex, currentSubset, subsetSize):
    if len(currentSubset) == subsetSize:
        print(" ".join(str(number) for number in currentSubset))
        return

    for index in range(startIndex, len(numbers)):
        currentSubset.append(numbers[index])
        generateSubsetsBySize(numbers, index + 1, currentSubset, subsetSize)
        currentSubset.pop()


def main():
    n = int(input())
    numbers = list(range(1, n + 1))

    print("Permutations:")
    generatePermutations(numbers, [], set())

    print("Non-empty subsets:")
    for subsetSize in range(1, n + 1):
        generateSubsetsBySize(numbers, 0, [], subsetSize)


if __name__ == "__main__":
    main()
