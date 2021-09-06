#pragma once
#include "ProductTypes.h"
#include "Categories.h"
#include "Models.h"
#include "Brands.h"

class ProductTypeDTO {

public:
	ProductTypeDTO() {

	}

	ProductTypeDTO(PRODUCT_TYPES* productType) {
		this->productType = *productType;
	}

	ProductTypeDTO(PRODUCT_TYPES productType, CATEGORIES category, MODELS model, BRANDS brand) {
		this->productType=productType;
		this->category=category;
		this->brand=brand;
		this->model=model;
	}

	~ProductTypeDTO() {

	}

public:
	PRODUCT_TYPES productType;
	CATEGORIES category;
	MODELS model;
	BRANDS brand;

};