namespace ZOM {
	typedef std::function<void(Event&)> eventCallbackFn;

	struct ZOM_API WindowParam {
		std::string name;
		int width;
		int height;
		bool vsync;
		eventCallbackFn eventFunc;

		WindowParam():
		name("blank"),
		width(640),
		height(480),
		vsync(true),
		eventFunc([](Event&) {/* ZOM_CRITICAL("No event callback function");*/ })
		{}
	};

	class ZOM_API Window {
	public:
		virtual ~Window() {};

		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual bool isVsync() const = 0;
		virtual std::string getName() const = 0;

		virtual void setEventCallbackFn(const eventCallbackFn& fun) = 0;
		virtual void setVsync(bool state) = 0;
		virtual void resize(const std::pair<int, int>& dims) = 0;

		virtual void update() = 0;

		static Window* createWindow(const WindowParam& param = WindowParam());
	};
}