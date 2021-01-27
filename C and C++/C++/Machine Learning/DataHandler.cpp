#define _CRT_SECURE_NO_DEPRECATE
#include "DataHandler.h"
#include <algorithm>
#include <random>
#include <iostream>

void DataHandler::readInputData(std::string path)
{
    uint32_t magic = 0;
    uint32_t nImages = 0;
    uint32_t rows = 0;
    uint32_t cols = 0;

    uint32_t headers[4];
    char bytes[4];
    FILE* f = fopen(path.c_str(), "rb");
    if (f)
    {
        uint32_t i = 0;
        while (i < 4)//4 headers
        {
            if (fread(bytes, sizeof(bytes), 1, f))
            {
                /*switch (i)
                {
                case 0:
                    magic = format(bytes);
                    break;
                case 1:
                    nImages = format(bytes);
                    break;
                case 2:
                    rows = format(bytes);
                    break;
                case 3:
                    cols = format(bytes);
                    break;
                }*/
                headers[i] = format(bytes);
                ++i;
            }
        }
        printf("Done getting images file header.\n");
        printf("magic: 0x%08x\n", headers[0]);

        printf("nImages: 0x%08x\n", headers[1]);

        printf("rows: 0x%08x\n", headers[2]);

        printf("cols: 0x%08x\n", headers[3]);
        exit(1);
        uint32_t image_size = rows * cols;
        for (i = 0; i < nImages; i++)
        {
            if (i%10000 == 0)std::cout << i << "\n";
            Data d;
            d.setFeatureVector(std::vector<uint8_t>());
            uint8_t element[1];
            for (int j = 0; j < image_size; j++)
            {
                //std::cout << "\t" << j << "\n";
                if (fread(element, sizeof(element), 1, f))
                {
                    d.appendToFeatureVector(*element);
                }
            }
            dataArray.push_back(d);
        }
        printf("Successfully read %lu data entries.\n", dataArray.size());
        printf("The Feature Vector Size is: %d\n", dataArray[0].getFeatureVectorSize());
    }
    else
    {
        printf("Invalid Input File Path\n");
        exit(1);
    }
}
void DataHandler::readLabelData(std::string path)
{
    uint32_t magic = 0;
    uint32_t nLabels = 0;
    char bytes[4];
    FILE* f = fopen(path.c_str(), "rb");
    if (f)
    {
        int i = 0;
        while (i < 2)//2 Headers
        {
            if (fread(bytes, sizeof(bytes), 1, f))
            {
                switch (i)
                {
                case 0:
                    magic = format(bytes);
                    break;
                case 1:
                    nLabels = format(bytes);
                    break;
                }
                ++i;
            }
        }

        for (i = 0; i < nLabels; i++)
        {
            uint8_t element[1];
            if (fread(element, sizeof(element), 1, f))
                dataArray[i].setLabel(*element);
        }
        printf("Done getting labels file header.\n");
    }
    else
    {
        printf("Invalid Label File Path\n");
        exit(1);
    }
}

//converts high endian to little indian (required for Intel Processors)
uint32_t DataHandler::format(const char (&bytes)[4]) const
{
    return (uint32_t)((bytes[0] << 24) |
        (bytes[1] << 16) |
        (bytes[2] << 8) |
        (bytes[3]));
}
