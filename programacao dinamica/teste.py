def charada(v, h):
    t = len(v)
    for i in range(h, t):
        temp = v[i]
        j = i

        while j >= h and v[j - h] > temp:
            v[j] = v[j - h]
            j -= h
        v[j] = temp

    print(''.join(v))


def main():
    a = input("Digite a string: ")
    i = int(input("Digite o valor de h: "))

    charada(list(a), i)


if __name__ == "__main__":
    main()
