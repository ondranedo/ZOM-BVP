class TrinageMesh {
public:
	float* getVertex() { return vertexD; }
	size_t getVertexSize() { return sizeof(vertexD); }
	unsigned int* getIndex() { return indexD; }
	size_t getIndexSize() { return sizeof(indexD); }
	void onUpdate()
	{
		if (m_Dir == LEFT)
		{
			vertexD[0] -= 0.1f * speed;
			vertexD[2] -= 0.1f * speed;
			vertexD[4] -= 0.1f * speed;
		}

		if (m_Dir == RIGHT)
		{
			vertexD[0] += 0.1f * speed;
			vertexD[2] += 0.1f * speed;
			vertexD[4] += 0.1f * speed;
		}

		if (m_Dir == TOP)
		{
			vertexD[1] += 0.1f * speed;
			vertexD[3] += 0.1f * speed;
			vertexD[5] += 0.1f * speed;
		}


		if (m_Dir == BOTTOM)
		{
			vertexD[1] -= 0.1f * speed;
			vertexD[3] -= 0.1f * speed;
			vertexD[5] -= 0.1f * speed;
		}
	}

	void moveLeft() { m_Dir = LEFT; }
	void moveRight() { m_Dir = RIGHT; }
	void moveTop() { m_Dir = TOP; }
	void moveBottom() { m_Dir = BOTTOM; }
	void moveStop() { m_Dir = NONE; }
	void speedUp() { speed += 0.01f; }
	void speedDown() { speed -= 0.01f; }
	void moveReset() {
		vertexD[0] = -0.5f; vertexD[1] = -0.5f;
		vertexD[2] = 0.0f; vertexD[3] = 0.5f;
		vertexD[4] = 0.5f; vertexD[5] = -0.5f;
		speed = 0.2f;
		m_Dir = NONE;
	}
private:
	float speed = 0.2f;
	float vertexD[6] = { -0.5f,-0.5f,0.0f, 0.5f,0.5f,-0.5f };
	unsigned int indexD[3] = { 0,1,2 };

	enum dir {
		NONE, LEFT, RIGHT, TOP, BOTTOM
	} m_Dir;
};
