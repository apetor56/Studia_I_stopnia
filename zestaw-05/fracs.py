from audioop import add


def NWD(a, b) -> int:
    return NWD(b, a % b) if b else a

def NWW(a, b) -> int:
    return a / NWD(a, b) * b

def swap_sign(frac):
    if frac[1] < 0:
        frac[0] *= -1
        frac[1] *= -1

def add_frac(frac1, frac2):
    m = NWW(frac1[1], frac2[1])
    l = m * frac1[0] / frac1[1] + m * frac2[0] / frac2[1]
    return [l, m]

def sub_frac(frac1, frac2):         # frac1 - frac2
    m = NWW(frac1[1], frac2[1])
    l = m * frac1[0] / frac1[1] - m * frac2[0] / frac2[1]
    return [l, m]

def mul_frac(frac1, frac2):        # frac1 * frac2
    return [frac1[0] * frac2[0], frac1[1] * frac2[1]]

def div_frac(frac1, frac2):        # frac1 / frac2
    return [frac1[0] * frac2[1], frac1[1] * frac2[0]]

def is_positive(frac):             # bool, czy dodatni
    return True if frac[0] > 0 and frac[1] > 0 else False

def is_zero(frac):                 # bool, typu [0, x]
    return True if frac[0] == 0 and frac[1] != 0 else False

def cmp_frac(frac1, frac2):        # -1 | 0 | +1
    m = NWW(frac1[1], frac2[1])
    frac1, frac2 = [m * frac1[0] / frac1[1], m], [m * frac2[0] / frac2[1], m]
    swap_sign(frac1)
    swap_sign(frac2)

    if(frac1[0] > frac2[0]): return 1
    elif(frac1[0] < frac2[0]): return -1
    return 0

def frac2float(frac) -> float:            # konwersja do float
    return float(frac[0] / frac[1])