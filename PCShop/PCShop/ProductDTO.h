#pragma once
#include "ProductTypes.h"
#include "Categories.h"
#include "Models.h"
#include "Brands.h"
#include "Products.h"
#include "Racks.h"
#include "Shelves.h"

class ProductDTO {

public:
	ProductDTO() {

	}

	ProductDTO(PRODUCTS* product) {
		this->product = *product;
	}

	ProductDTO(PRODUCTS product, PRODUCT_TYPES productType, CATEGORIES category, MODELS model, BRANDS brand, RACKS rack, SHELVES shelf) {
		this->productType = productType;
		this->product = product;
		this->category = category;
		this->brand = brand;
		this->model = model;
		this->rack = rack;
		this->shelf = shelf;
	}

	~ProductDTO() {

	}

public:
	PRODUCT_TYPES productType;
	PRODUCTS product;
	CATEGORIES category;
	MODELS model;
	BRANDS brand;
	RACKS rack;
	SHELVES shelf;

};