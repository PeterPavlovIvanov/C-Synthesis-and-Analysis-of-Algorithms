#pragma once
#include "MemoryArray.h"
#include "Racks.h"
#include "Brands.h"
#include "Models.h"
#include "ProductTypes.h"
#include "Shelves.h"
#include "Products.h"
#include "Categories.h"

#define FIX_TO_LAST_INDEX 1
#define COLUMN_WIDTH_BASIC 120
#define COLUMN_WIDTH_SMALL 90
#define COLUMN_WIDTH_TINY 65
#define COLUMN_WIDTH_DESCRIPTION 190

typedef MemoryArray<RACKS> RacksArray;
typedef MemoryArray<BRANDS> BrandsArray;
typedef MemoryArray<MODELS> ModelsArray;
typedef MemoryArray<PRODUCT_TYPES> ProductTypesArray;
typedef MemoryArray<PRODUCTS> ProductsArray;
typedef MemoryArray<CATEGORIES> CategoriesArray;
typedef MemoryArray<SHELVES> ShelvesArray;