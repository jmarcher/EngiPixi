.PHONY: clean All

All:
	@echo "----------Building project:[ Engine - Debug ]----------"
	@cd "Engine" && "$(MAKE)" -f  "Engine.mk"
clean:
	@echo "----------Cleaning project:[ Engine - Debug ]----------"
	@cd "Engine" && "$(MAKE)" -f  "Engine.mk" clean
