class SquareMesh {
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
			vertexD[6] -= 0.1f * speed;
		}

		if (m_Dir == RIGHT)
		{
			vertexD[0] += 0.1f * speed;
			vertexD[2] += 0.1f * speed;
			vertexD[4] += 0.1f * speed;
			vertexD[6] += 0.1f * speed;
		}

		if (m_Dir == TOP)
		{
			vertexD[1] += 0.1f * speed;
			vertexD[3] += 0.1f * speed;
			vertexD[5] += 0.1f * speed;
			vertexD[7] += 0.1f * speed;
		}


		if (m_Dir == BOTTOM)
		{
			vertexD[1] -= 0.1f * speed;
			vertexD[3] -= 0.1f * speed;
			vertexD[5] -= 0.1f * speed;
			vertexD[7] -= 0.1f * speed;
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
		vertexD[0] = -1.0f; vertexD[1] = -1.0f;
		vertexD[2] = -1.0f; vertexD[3] =  1.0f;
		vertexD[4] =  1.0f; vertexD[5] =  1.0f;
		vertexD[6] =  1.0f; vertexD[7] = -1.0f;
		speed = 0.2f;
		m_Dir = NONE;
	}
	const unsigned int g_IndexCount = 6;
private:
	float speed = 0.2f;
	float vertexD[8] = { 
		-1.0f,-1.0f,
		-1.0f, 1.0f,
		 1.0f, 1.0f,
		 1.0f,-1.0f
	};
	unsigned int indexD[6] = {
		0,1,2,
		0,2,3
	};

	enum dir {
		NONE, LEFT, RIGHT, TOP, BOTTOM
	} m_Dir;
};
