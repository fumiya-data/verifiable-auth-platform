package engineclient

import (
	"bytes"
	"encoding/json"
	"errors"
)

func decodeResponse[T any](raw []byte) (Response[T], error) {
	var response Response[T]
	trimmed := bytes.TrimSpace(raw)
	if len(trimmed) == 0 {
		return Response[T]{}, errors.New("empty engine response")
	}

	if err := json.Unmarshal(trimmed, &response); err != nil {
		return Response[T]{}, err
	}

	return response, nil
}
