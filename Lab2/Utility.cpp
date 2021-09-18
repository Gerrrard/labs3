#include "pch.h"
#include "Utility.h"
#include "ACurve.h"
#include <iostream>

namespace Menu {
    void start(Lab2::ASpiral* spir) {
        void (*dialog_functions[8])(Lab2::ASpiral * spiral) = { menuExit, menuParametrInput, menuDistance, menuSectorArea,
            menuRingArea, menuTurnArea, menuLength , menuCurvatureRadius };

        int opt = 10;

        while (opt) {
            opt = menu();
            dialog_functions[opt](spir);
        }
    }

    int menu() {
        const char* msg = "";
        const char* msg_menu0 = "0) Exit";
        const char* msg_menu1 = "1) Input parameter";
        const char* msg_menu2 = "2) Output distance from curve start, depending on angle";
        const char* msg_menu3 = "3) Output sector area between 2 radiuses (angle difference <2*Pi)";
        const char* msg_menu4 = "4) Output area of i-th ring";
        const char* msg_menu5 = "5) Output area of figure under i-th ring";
        const char* msg_menu6 = "6) Output curve length, depending on angle";
        const char* msg_menu7 = "7) Output curvature radius, depending on angle";
        int errcode, option;

        std::cout << msg_menu0 << std::endl << msg_menu1 << std::endl << msg_menu2 << std::endl
            << msg_menu3 << std::endl << msg_menu4 << std::endl << msg_menu5 << std::endl
            << msg_menu6 << std::endl << msg_menu7 << std::endl;

        do {
            errcode = Utility::getNum<int>(option, msg);
            if (errcode == -2) msg = "Error, not an integer number, repeat: ";
            if (!errcode && (option < 0 || option > 7)) {
                errcode = 1;
                msg = "Error, not an option of menu, repeat: ";
            }
        } while (errcode);
        return option;
    }

    void menuExit(Lab2::ASpiral* spir) {
        std::cout << "Finished" << std::endl;
    }

    void menuParametrInput(Lab2::ASpiral* spir) {
        double par;
        int errcode;
        const char* msg = "";

        std::cout << "Enter parametr" << std::endl;
        do {
            errcode = Utility::getNum<double>(par, msg);
            if (errcode == -2) msg = "Error, not a float, repeat: ";
        } while (errcode);
        spir->setA(par);
        std::cout << "Parametr now equals " << spir->getA() << std::endl;
    }

    void menuDistance(Lab2::ASpiral* spir) {
        double ang;
        int errcode;
        const char* msg = "";

        std::cout << "Enter angle" << std::endl;
        do {
            errcode = Utility::getNum<double>(ang, msg);
            if (errcode == -2) msg = "Error, not a float, repeat: ";
        } while (errcode);
        std::cout << "Distance from center equals " << spir->distance(ang) << std::endl;
    }

    void menuSectorArea(Lab2::ASpiral* spir) {
        double rad1, rad2;
        int errcode;
        const char* msg = "";

        std::cout << "Enter first radius" << std::endl;
        do {
            errcode = Utility::getNum<double>(rad1, msg);
            if (!errcode && (rad1 < 0)) {
                errcode = 1;
                msg = "Error, radius should be >= 0, repeat: ";
            }
            if (errcode == -2) msg = "Error, not a float, repeat: ";
        } while (errcode);

        std::cout << "Enter second radius" << std::endl;
        do {
            errcode = Utility::getNum<double>(rad2, msg);
            if (!errcode && (rad2 < 0)) {
                errcode = 1;
                msg = "Error, radius should be >= 0, repeat: ";
            }
            if (errcode == -2) msg = "Error, not a float, repeat: ";
        } while (errcode);
        std::cout << "Area between radiuses equals " << spir->sectorArea(rad1, rad2) << std::endl;
    }

    void menuRingArea(Lab2::ASpiral* spir) {
        int i;
        int errcode;
        const char* msg = "";

        std::cout << "Enter ring number" << std::endl;
        do {
            errcode = Utility::getNum<int>(i, msg);
            if (errcode == -2) msg = "Error, not an integer number, repeat: ";
            if (!errcode && (i < 0)) {
                errcode = 1;
                msg = "Error, ring number should be positive, repeat: ";
            }
        } while (errcode);
        std::cout << "Area of " << i << " ring equals " << spir->figureRingAreaTurn(i) << std::endl;
    }

    void menuTurnArea(Lab2::ASpiral* spir) {
        int i;
        int errcode;
        const char* msg = "";

        std::cout << "Enter turn number" << std::endl;
        do {
            errcode = Utility::getNum<int>(i, msg);
            if (errcode == -2) msg = "Error, not an integer number, repeat: ";
            if (!errcode && (i < 0)) {
                errcode = 1;
                msg = "Error, turn number should be positive, repeat: ";
            }
        } while (errcode);
        std::cout << "Area of figure under" << i << " turn equals " << spir->figureAreaTurn(i) << std::endl;
    }

    void menuLength(Lab2::ASpiral* spir) {
        double ang;
        int errcode;
        const char* msg = "";

        std::cout << "Enter angle" << std::endl;
        do {
            errcode = Utility::getNum<double>(ang, msg);
            if (errcode == -2) msg = "Error, not a float, repeat: ";
        } while (errcode);
        std::cout << "Curve length from center equals " << spir->curveLength(ang) << std::endl;
    }

    void menuCurvatureRadius(Lab2::ASpiral* spir) {
        double ang;
        int errcode;
        const char* msg = "";

        std::cout << "Enter angle" << std::endl;
        do {
            errcode = Utility::getNum<double>(ang, msg);
            if (errcode == -2) msg = "Error, not a float, repeat: ";
        } while (errcode);
        std::cout << "Curvature radius equals " << spir->curvature(ang) << std::endl;
    }
}

namespace Utility {
    bool is_Int(const char* S) {
        const char* temp = "0123456789-+";
        unsigned point_count = 0;

        for (unsigned int i = 0; i < strlen(S); i++) {
            if ((i > 0) && (S[i] == '+' || S[i] == '-')) return false;
            if (!strchr(temp, S[i])) return false;
        }
        return true;
    }
    bool is_Double(const char* S) {
        const char* temp = ".0123456789-+";
        unsigned point_count = 0;

        for (unsigned int i = 0; i < strlen(S); i++) {
            if ((i > 0) && (S[i] == '+' || S[i] == '-')) return false;
            if (S[i] == '.') {
                point_count++;
                if (point_count > 1) return false;
            }
            if (!strchr(temp, S[i])) return false;
        }
        return true;
    }

    template <class V> int getNum(V& a, const char* msg)
    {
        if (msg != nullptr) {
            std::cout << std::endl << msg;
        }

        const int N = 256;
        char S[N];

        std::cin.getline(S, N, '\n');
        if (!is_Double(S) || S[0] == '\0') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -2;
        }

        if (is_Int(S)) {
            a = atoi(S);
        }
        else {
            a = atof(S);
        }

        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }

        return 0;
    }
}