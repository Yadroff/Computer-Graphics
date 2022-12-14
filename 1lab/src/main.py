from enum import Enum

import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import axisartist


class Param(Enum):
    LEFT = 0
    RIGHT = 2 * np.pi
    STEP = 0.01


def rho(a, phi):
    return a * (1 - np.cos(phi))


def x(a, phi):
    return rho(a, phi) * np.cos(phi)


def y(a, phi):
    return rho(a, phi) * np.sin(phi)


def main():
    a = int(input("Введите коэффициент a: "))
    if a <= 0:
        raise ValueError("a должен быть строго больше нуля")
    t = np.arange(
        Param.LEFT.value, Param.RIGHT.value + Param.STEP.value, Param.STEP.value
    )

    fig = plt.figure()
    ax = axisartist.Subplot(fig, 111)
    fig.add_axes(ax)

    ax.axis["bottom"].set_axisline_style("->", size=1.5)
    ax.axis["left"].set_axisline_style("->", size=1.5)
    ax.axis["top"].set_visible(False)
    ax.axis["right"].set_visible(False)
    ax.set_xlabel("Ось X")
    ax.set_ylabel("Ось Y")

    plt.plot(x(a, t), y(a, t))

    plt.show()


if __name__ == "__main__":
    main()
