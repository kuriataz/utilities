#pragma once
#include <iostream>
#include <array.hpp>

template<typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;

};

template<typename T>
Node<T> *new_node(T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

template<typename T>
void insert_node(Node<T> **head, Node<T> *node_to_insert)
{
    if (*head == nullptr)
    {
        *head = node_to_insert;
        node_to_insert->next = node_to_insert;
        node_to_insert->prev = node_to_insert;
        return;
    }
    Node<T> *last = (*head)->prev;
    last->next = node_to_insert;
    node_to_insert->prev = last;
    (*head)->prev = node_to_insert;
    node_to_insert->next = *head;

    *head = node_to_insert;
}

template<typename T>
void delete_node(Node<T> **head, Node<T> *node_to_delete)
{
    if (*head == nullptr)
    {
        return;
    }
    if (*head == node_to_delete)
    {
        *head = (*head)->next;
    }
    node_to_delete->prev->next = node_to_delete->next;
    node_to_delete->next->prev = node_to_delete->prev;
    free(node_to_delete);
}

template<typename T>
Node<T>* search_node(Node<T> *head, T data)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node<T> *current = head;
    do
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    } while (current != head);

    return nullptr;
}

template<typename T>
Array<T> list_to_array(Node<T> *head)
{
    Array<T> arr;
    if (head == nullptr)
    {
        return arr;
    }
    Node<T> *current = head->prev;
    do
    {
        arr.push_back(current->data);
        current = current->prev;
    } while (current != head->prev);
    return arr;
}

template<typename T>
void print_count_list(Node<T> *head, int count, bool is_rev)
{
    if (count == 0 || head == nullptr)
    {
        return;
    }
    int i = 0;
    if (!is_rev)
    {
        Node<T> *current = head->prev;
        do
        {
            i++;
            std::cout << i << " " << current->data << "\n";
            current = current->prev;
        } while (current != head->prev && i != count);
    }
    else
    {
        Node<T> *current = head;
        do
        {
            std::cout << count - i << " " << current->data << "\n";
            i++;
            current = current->next;
        } while (current != head && i != count);
    }
}
