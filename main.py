
cache = []

def main() -> None:

    peticiones = [3,1,4,8,5,9,3,2,5,4]
    
    k = 2

    
    cache = peticiones[:k]
    peticiones = peticiones[k:]
    fallos = k

    for pe_i, pe in enumerate(peticiones):
        if pe in cache:
            print(f"HIT: {pe}")
            continue

        to_remove_pag = 0
        to_remove = -1
        for (pag_i, pag) in enumerate(cache):
            if (pag not in peticiones[pe_i:]):
                to_remove_pag = pag_i
                break

            for j in range(pe_i+1,len(peticiones)):
                if peticiones[j] == pag:
                    if to_remove < j:
                           to_remove = j
                           to_remove_pag = pag_i

        cache[to_remove_pag] = pe
        fallos+=1
        print(f"cache:{cache}") 
    

    print(fallos)

if __name__ == "__main__":
    main()
