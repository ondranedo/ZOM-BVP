namespace ZOM {
	typedef std::function<void(Event&)> eventCallbackFn;

	struct ZOM_API WindowParam {
		std::string name;
		std::pair<int, int> dimensions;

		WindowParam():
		name("blank"),
		dimensions({640,480})
		{}
	};

	class ZOM_API Window {
	public:
		virtual ~Window() {};

		virtual inline std::string name() const = 0;
		virtual inline std::pair<int, int> dime() const = 0;
		virtual inline bool isVsync() const = 0;

		virtual void setEventCallbackFn(const eventCallbackFn& fun) = 0;
		virtual void setVsync(bool state) = 0;
		virtual void resize(const std::pair<int, int>& dims) = 0;

		// Runs every frame
		virtual void update() = 0;

		static Window* createWindow(const WindowParam& param = WindowParam());
	};
}